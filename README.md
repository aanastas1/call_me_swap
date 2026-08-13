*This project has been created as part of the 42 curriculum by anakloch, aloiko.*

# Push_swap

### Description
`push_swap` is a C program that sorts a list of integers using two stacks (`a` and `b`) and a restricted set of Push_swap operations:
`sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr`.

The program outputs the **smallest** sequence of operations (in the Push_swap operation model) that sorts stack `a` in ascending order, where the **smallest number is on top**.

This project also enforces algorithmic complexity in a concrete way: the programm chooses and executes different sorting strategies at runtime, and the claimed complexity classes reflects the number of **generated Push_swap operations**.

### Instructions
#### Build
This project compiles with a non-relinking Makefile and provide the required files at the repository level:
- `push_swap.c`, `push_swap.h`
- `Makefile`
- `libft.a` (built as part of the submission)
- `README.md`

Typical build:
```sh
make
```

#### Usage
- Sort normally (default is the adaptive strategy):
```sh
./push_swap "3 2 1"
```

- Force a specific strategy:
```sh
./push_swap --simple   "3 2 1"
./push_swap --medium   "3 2 1"
./push_swap --complex  "3 2 1"
./push_swap --adaptive "3 2 1"
```

- Benchmark mode (prints to **stderr** only when the flag is present):
```sh
./push_swap --bench --adaptive "3 2 1"
```
- If no parameters are specified, the program does not output anything and does not return the prompt.
- On error, it prints `Error\n` to **stderr** and exit.
- The program rejects invalid input (non-integers, out-of-range values, duplicates, etc.).

### Resources
References commonly used for implementing Push_swap:
- Push_swap operations and stack simulation
- Variance of sorting strategies over input disorder
- Discrete data normalization (mapping input values to ranks/indices)

AI usage:
- AI was used to quickly polish and format the `README.md` text.
- AI did not affect the sorting logic or algorithm correctness.

### Strategies (all included in the binary)
The binary embeds all four strategies and expose their name and complexity class in `--bench` mode.
- `--simple`: Simple sorting strategy with target complexity **O(n^2)** (baseline for small or low-disorder inputs).
- `--medium`: Medium sorting strategy with target complexity **O(n√n)**.
- `--complex`: Complex sorting strategy with target complexity **O(n log n)**.
- `--adaptive` (default): Adaptive strategy that computes a disorder metric and selects one of the above regimes based on thresholds.

In `--bench` mode, after sorting the program prints (to **stderr**) :
- the computed disorder in `%` with two decimals,
- the selected strategy name and its theoretical complexity class,
- total number of operations generated,
- counts of each operation type:
  `sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr`.

### Disorder metric (mandatory)
Your program computes disorder **before any moves**.

**Definition (as used in this repository):**
We compute disorder from stack `a`:
- Consider all pairs `(i, j)` with `i < j`.
- Each time `a[i] > a[j]`, it counts as a mistake.
- `disorder = mistakes / total_pairs`, producing a value in `[0, 1]`.

The `disorder` value is calculated using integer arithmetic and then converted to a floating-point number.

### Algorithm explanation and justification (mandatory)

#### How strategy selection works (Adaptive)
- The disorder computation is used to pick the strategy:
  - Low disorder (`disorder < 0.05`) → use `--simple` (O(n^2))
  - Medium disorder (`0.2 ≤ disorder < 0.35`) → use `--medium` (O(n√n))
  - High disorder (`disorder ≥ 0.35`) → use `--complex` (O(n log n))

#### Justification for each required regime/strategy

**1) Simple strategy (`--simple`) — target O(n^2)**
- Describe the approach you use in `--simple` (e.g., insertion-like behavior using `a`/`b`, repeated min/max extraction, etc.).
- Explain why the operation count is bounded by **O(n^2)** in the Push_swap model.
- State any space usage (excluding global variables restrictions).

**2) Medium strategy (`--medium`) — target O(n√n)**
- Describe the chunk/block/bucket/range method you use.
- Explain how chunk/range size leads to **O(n√n)** operations.
- State any space usage.

**3) Complex strategy (`--complex`) — target O(n log n)**
- Describe the method you use (e.g., radix by ranked indices, two-stack merge approach, quick-like partitioning approach, etc.).
- Explain why the number of generated operations is bounded by **O(n log n)** in this operation model.
- State any space usage.

#### Complexity argument for the Adaptive strategy
- Show that the adaptive selection does not break complexity targets, because each disorder regime picks one strategy whose operation count matches the required class.
- Explain the additional overhead of measuring disorder and selecting a strategy, and why it doesn’t invalidate the complexity class in the operation model.

```zsh
=== COMPLEXITY — EMPIRICAL PROOF ===
  Read down each ratio column: the one that stays flat is the true class.
  Growth is ops(2n)/ops(n) — expect ~4.0 for n^2, ~2.83 for n√n, ~2.1 for n*log n.

  --simple   expected O(n^2)
       n       ops      ops/n^2     ops/n√n    ops/nlog2n   growth
  ------------------------------------------------------------------
      25       125       .2000      1.0000      1.0766         -
      50       414       .1656      1.1709      1.4669      3.31
     100      1465       .1465      1.4650      2.2049      3.53
     200      5536       .1384      1.9572      3.6209      3.77
     400     20735       .1295      2.5918      5.9967      3.74
     500     32583       .1303      2.9143      7.2678      3.91
    1000    124772       .1247      3.9456     12.5193      3.82

  --medium   expected O(n*sqrt n)
       n       ops      ops/n^2     ops/n√n   ops/nlog2n   growth
  ------------------------------------------------------------------
      25        98       .1568       .7840       .8440         -
      50       242       .0968       .6844       .8575      2.46
     100       571       .0571       .5710       .8593      2.35
     200      1491       .0372       .5271       .9752      2.61
     400      3782       .0236       .4727      1.0937      2.53
     500      5085       .0203       .4548      1.1342      2.48
    1000     13422       .0134       .4244      1.3467      2.63
    3000     64680       .0071       .3936      1.8664      2.73
    5000    136142       .0054       .3850      2.2157      2.72
   10000    375972       .0037       .3759      2.8293      2.76

  --complex   expected O(n*log n)
       n       ops      ops/n^2     ops/n√n   ops/nlog2n   growth
  ------------------------------------------------------------------
      25       128       .2048      1.0240      1.1024         -
      50       333       .1332       .9418      1.1799      2.60
     100       810       .0810       .8100      1.2191      2.43
     200      1872       .0468       .6618      1.2244      2.31
     400      4503       .0281       .5628      1.3023      2.40
     500      5772       .0230       .5162      1.2874      2.24
    1000     12951       .0129       .4095      1.2994      2.24
    3000     45748       .0050       .2784      1.3201      2.22
    5000     83694       .0033       .2367      1.3621      2.14
   10000    178214       .0017       .1782      1.3411      2.12
   20000    382496       .0001       .1352      1.3385      2.14
   40000    851359       .0001       .1064      1.3922      2.22
   80000   1748348       .0000       .0772      1.3417      2.05
```
---

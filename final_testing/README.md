*This project has been created as part of the 42 curriculum by anakloch, aloiko.*

# Push_swap

### Description
`push_swap` is a C program that sorts a list of integers using two stacks (`a` and `b`) and a restricted set of Push_swap operations:
`sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr`.

The program must output the **smallest** sequence of operations (in the Push_swap operation model) that sorts stack `a` in ascending order, where the **smallest number is on top**.

This project also enforces algorithmic complexity in a concrete way: your C code must choose and execute different sorting strategies at runtime, and the claimed complexity classes must reflect the number of **generated Push_swap operations**.

### Instructions
#### Build
This project must compile with a non-relinking Makefile and provide the required files at the repository level:
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

Notes:
- If no parameters are specified, the program must not output anything and must return the prompt.
- On error, it must print `Error\n` to **stderr** and exit.
- The program must reject invalid input (non-integers, out-of-range values, duplicates, etc.).

### Resources
References commonly used for implementing Push_swap:
- Push_swap operations and stack simulation
- Variance of sorting strategies over input disorder
- Discrete data normalization (mapping input values to ranks/indices, if used)
- Variadic/debug output (if used in the project)

AI usage:
- AI was used to quickly polish and format the `README.md` text.
- AI did not affect the sorting logic or algorithm correctness.

### Strategies (all included in the binary)
The binary must embed all four strategies and expose their name and complexity class in `--bench` mode.

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
Your program must compute disorder **before any moves**.

**Definition (as used in this repository):**
We compute disorder from stack `a`:
- Consider all pairs `(i, j)` with `i < j`.
- Each time `a[i] > a[j]`, it counts as a mistake.
- `disorder = mistakes / total_pairs`, producing a value in `[0, 1]`.

**TODO (fill with your exact implementation details):**
- How you compute `total_pairs` and handle edge cases (e.g., `n < 2`).
- Whether you compute `disorder` using integer arithmetic then convert, or directly as floating point.
- Confirm thresholds are exactly:
  - `disorder < 0.2`  → O(n^2) regime
  - `0.2 ≤ disorder < 0.5` → O(n√n) regime
  - `disorder ≥ 0.5` → O(n log n) regime

### Algorithm explanation and justification (mandatory)
Your README must include a detailed explanation and justification of the algorithm selected for this project, including how it meets the required complexity targets **in the Push_swap operation model** (i.e., by counting generated operations, not array-theory time).

#### How strategy selection works (Adaptive)
**TODO (fill with your exact logic):**
- The disorder computation is used to pick the strategy:
  - Low disorder (`disorder < 0.2`) → use `--simple` (O(n^2))
  - Medium disorder (`0.2 ≤ disorder < 0.5`) → use `--medium` (O(n√n))
  - High disorder (`disorder ≥ 0.5`) → use `--complex` (O(n log n))
- Provide a short rationale for why these thresholds map well to your internal techniques.

#### Justification for each required regime/strategy
**Important:** Complexity must be argued as an *upper bound on the number of operations generated*.

**1) Simple strategy (`--simple`) — target O(n^2)**
**TODO (fill with your exact internal technique):**
- Describe the approach you use in `--simple` (e.g., insertion-like behavior using `a`/`b`, repeated min/max extraction, etc.).
- Explain why the operation count is bounded by **O(n^2)** in the Push_swap model.
- State any space usage (excluding global variables restrictions).

**2) Medium strategy (`--medium`) — target O(n√n)**
**TODO (fill with your exact internal technique):**
- Describe the chunk/block/bucket/range method you use.
- Explain how chunk/range size leads to **O(n√n)** operations.
- State any space usage.

**3) Complex strategy (`--complex`) — target O(n log n)**
**TODO (fill with your exact internal technique):**
- Describe the method you use (e.g., radix by ranked indices, two-stack merge approach, quick-like partitioning approach, etc.).
- Explain why the number of generated operations is bounded by **O(n log n)** in this operation model.
- State any space usage.

#### Complexity argument for the Adaptive strategy
**TODO (fill with your exact reasoning):**
- Show that the adaptive selection does not break complexity targets, because each disorder regime picks one strategy whose operation count matches the required class.
- Explain the additional overhead of measuring disorder and selecting a strategy, and why it doesn’t invalidate the complexity class in the operation model.

---

### AI usage (final note)
- **Task:** “polish and format the README.md text.”
- **Affected parts:** documentation formatting/wording only.
- **Not affected:** sorting algorithms and operation generation logic.

---

Send the exact details for the three TODO blocks (how disorder is computed/handled for small `n`, what each of the four strategies actually does internally, and the exact thresholds if they differ), and I’ll replace the placeholders with precise, correct text matching your implementation.
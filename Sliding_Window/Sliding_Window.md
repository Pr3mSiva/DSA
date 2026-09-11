# Sliding Window Notes

## Problem Setup
* **Array:** `a = [1, 2, 3, 4, 5, 6]`
* **Target:** `Sum k = 3` (Window size)

## Approach 1: Naive Sliding Window
Visualizing the windows and their sums:
* `[1, 2, 3]` -> Sum: **6**
* `[2, 3, 4]` -> Sum: **9**
* `[3, 4, 5]` -> Sum: **12**
* `[4, 5, 6]` -> Sum: **15**

**Key Observations:**
* We need to find the sub-array with the max sum.
* This is a naive approach as it adds redundantly every number.
* This is also considered a sliding window technique.

---

## Approach 2: Optimized Sliding Window
Using the previous sum to calculate the next sum efficiently without recalculating the entire window.

* **Array:** `a = [1, 2, 3, 4, 5, 6]`
* **Initial window:** `[1, 2, 3]` -> Sum: **6**
* **Next window:** `[2, 3, 4]` -> Sum: `6 - 1 + 4 = 9` *(Previous sum - element leaving + element entering)*

**Formula:**
> `Current sum = current_sum - a[i-1] + a[right]`

**Key Observations:**
* This performs a lesser number of operations compared to the naive approach
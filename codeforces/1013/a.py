def can_arrange_columns(x, m, n):
    """
    Determine if x columns can be arranged in m columns with non-adjacent batches 
    where each batch is <= n columns.
    
    Args:
    x (int): Total number of columns to arrange
    m (int): Total available column slots
    n (int): Maximum batch size
    
    Returns:
    bool: True if arrangement is possible, False otherwise
    
    Time complexity: O(1)
    Space complexity: O(1)
    """
    # If x is 0, it's always possible
    if x == 0:
        return True
    
    # Calculate the maximum number of batches that can be placed
    # Each batch requires space for cols + an empty col (except potentially the last)
    max_gaps = (m + 1) // (n + 1)
    
    # Maximum total columns that can be placed
    max_columns = max_gaps * n
    
    # Check if we can fit all x columns
    return x <= max_columns

# Comprehensive test cases
def test_column_arrangement():
    # Test cases
    test_cases = [
        # x, m, n, expected_result
        (3, 5, 2, True)
    ]
    
    for x, m, n, expected in test_cases:
        result = can_arrange_columns(x, m, n)
        print(f"x={x}, m={m}, n={n}: {result} (Expected: {expected})")
        assert result == expected, f"Failed for x={x}, m={m}, n={n}"
    
    print("All test cases passed!")

# Run the tests
test_column_arrangement()

# Enter any assumptions you're making about about the problem or any notes you want taken into account here

# This method takes in an array of integers and returns a version of that array
# with all numbers that appear more than once removed
def remove_all_duplicated_numbers(arr):
    return arr

def run_single_test(test_number, input, expected):
    output = remove_all_duplicated_numbers(input)
    if output == expected:
        print("Test " + str(test_number) + " PASSED")
    else:
        print("Test " + str(test_number) + " FAILED")
        print("    Expected: " + str(expected))
        print("    Actual: " + str(output))

def run_tests():
    # Test 1: simple array
    run_single_test(1, [0, 0, 1, 1, 1, 2, 3], [2, 3])

    # Test 2: empty array
    run_single_test(2, [], [])

    # Test 3: one element array
    run_single_test(3, [1], [1])

    # Test 4: all one element array
    run_single_test(4, [2, 2, 2, 2, 2, 2], [])

    # Test 5: complex test
    run_single_test(5, [0, 0, 2, 2, 3, 3, 3, 3, 2, 2, 2, 3, 3, 5, 4, 6, 2, 2, 2, 1], [5, 4, 6, 1])

# Run tests to see how we did
run_tests()

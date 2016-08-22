# A solution to the problem.txt in Python with test cases :)
# To try this on your own simply delete the contents of bubblesort and fill it in yourself

# Enter any assumptions you're making about about the problem or any notes you want taken into account here
# - Array will always be of comparable elements and no error handling of improper arrays is necessary

# Bubblesort is an O(n^2) time complexity and O(1) storage complexity sort algorithm. This method implements the
# algorithm. This method requires an array of elements that are comparable via '<' and '>'
def bubblesort(array):
    array_length = len(array)
    # If array is trivially sorted then just return 
    if array_length is 0 or array_length is 1:
        return
    else:
        for i in range (0, array_length):
            # We can shorten this inner loop by 1 every time since the largest element among those remaining will
            # have 'bubbled up' to the correct place
            for j in range(1, array_length-i):
                # If the elements we're looking at are not in the right order then swap them
                if array[j] < array[j-1]:
                    temp = array[j]
                    array[j] = array[j-1]
                    array[j-1] = temp

# Test running code
def run_single_test(test_number, input, expected):
    input_copy = input
    bubblesort(input_copy)
    if input_copy == expected:
        print("Test " + str(test_number) + " PASSED")
    else:
        print("Test " + str(test_number) + " FAILED")
        print("    expected: " + str(expected))
        print("    actual:   " + str(input_copy)) 

def run_tests():
    # 1. Simple case
    run_single_test(1, [0, 3, 2, 1], [0, 1, 2, 3])
    # 2. Empty array
    run_single_test(2, [], [])
    # 3. Single element array
    run_single_test(3, [1], [1])
    # 4. Strings, just for fun :)
    run_single_test(4, ["aab", "a", "ddf", "bcd"], ["a", "aab", "bcd", "ddf"])
    # 5. Larger array, negative numbers, duplicates
    run_single_test(5, [3, -1, 100, 4, 5, 3, 4, 5, 9, -10, 5, 0], [-10, -1, 0, 3, 3, 4, 4, 5, 5, 5, 9, 100])

run_tests()

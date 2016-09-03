# Enter any assumptions you're making about about the problem or any notes you want taken into account here
# 

# To try this problem on your own simply delete the contents of does_sum_exist and write your own version.
# If you want a hint or a starting point you can look at naive_does_sum_exist, which is a worse (but
# functional!) solution. If you're feeling confident you can delete this method too.
# You can use the existing test cases to test your solution

# This method takes in three arrays of integers as well as a 'target sum' and returns true if there exist
# an integer from each array that adds up to be the target sum or else false
def does_sum_exist(arr1, arr2, arr3, target_sum):
    # This method is an n^2 solution overall. It uses a hash table to be able to determine if there exists
    # numbers from two of the arrays that add up to a target sum in O(n) time. It does this within a loop
    # that takes the third array into account. Storage complexity is O(n).

    # Fail quickly if any of the arrays are empty
    if len(arr1) is 0 or len(arr2) is 0 or len(arr3) is 0:
        return False

    for i in arr1:
        # This is the sum we're looking for 2 numbers from arr2 and arr3 to add up to
        new_target_sum = target_sum - i

        # This is the dictionary that we'll use to keep track of what's in arr2 so we can quickly look up
        # numbers in it that, combined with an arr3 value, would equal new_target_sum
        # We could (and probably should) use a Set instead since the value part of the key value pairs is
        # really not interesting to us - we only care whether or not a number has been seen. However, to
        # keep things vanilla we'll just use a dict. The idea is the same.
        seen_numbers = {}

        for j in arr2:
            if j not in seen_numbers:
                seen_numbers[j] = 1

        for k in arr3:
            if new_target_sum - k in seen_numbers:
                # If we've seen a number that combined with k will equal our target sum then we can return
                # true right now
                # Debug: print the three numbers
                # print("Target sum is " + str(target_sum) + " - three numbers are " + str(i) + " " + str(new_target_sum-k) + " " + str(k))
                return True

    # If we haven't found anything after looping through arr1 then no such number exists
    return False

# This method has the same input and output as does_sum_exist above - it just reaches a solution in a more
# inefficient way
def naive_does_sum_exist(arr1, arr2, arr3, target_sum):
    # This method simply loops through all 3 arrays in an O(n^3) algorithm to find three numbers that add up
    # to target_sum
    for i in arr1:
        for j in arr2:
            for k in arr3:
                if i + j + k == target_sum:
                    return True

    return False

# input is a tuple of the three input arrays plus the target sum
def run_single_test(test_number, input, expected):
    output = does_sum_exist(input[0], input[1], input[2], input[3])
    if output == expected:
        print("Test " + str(test_number) + " PASSED")
    else:
        print("Test " + str(test_number) + " FAILED")
        print("    arr1: " + str(input[0]))
        print("    arr2: " + str(input[1]))
        print("    arr3: " + str(input[2]))
        print("    target sum: " + str(input[3]))
        print("    Expected " + str(expected) + " but got " + str(output))

def run_tests():
    # Test 1: simple arrays, sum exists
    run_single_test(1, ([0, 1, 2], [5, 6], [10], 17), True)

    # Test 2: simple arrays, sum does not exist
    run_single_test(2, ([0, 1, 2], [5, 6], [10], 50), False)

    # Test 3: simple arrays with negative numbers, sum exists
    run_single_test(3, ([-10, 1, 2], [-3, 6], [10], -3), True)

    # Test 4: simple arrays with negative numbers, sum does not exist
    run_single_test(4, ([-10, 1, 2], [-3, 6], [10], -14), False)

    # Test 5: empty array, sum does not exist in the other 2 arrays
    run_single_test(5, ([5, 10, 6], [-3, 3], [], 100), False)

    # Test 6: empty array, sum exists in the other 2 arrays
    run_single_test(6, ([5, 10, 6], [-3, 3], [], 2), False)

    # Test 7: all empty arrays
    run_single_test(7, ([], [], [], 1), False)    

# Run tests to see how we did
run_tests()

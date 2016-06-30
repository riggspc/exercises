# Enter any assumptions you're making about about the problem or any notes you want taken into account here
# - I am assuming the phrase "removes all numbers that appear more than once" means
#   that the first number seen should be removed if that number appears elsewhere
#   ie. [0, 1, 0] -> [1]

# This method takes in an array of integers and returns a version of that array
# with all numbers that appear more than once removed (including the 'original'
# number)
# Simplistically the time and space complexity of this approach is both O(n)
# However this could be complicated by the cost of array insertion/deletion/appending
def remove_all_duplicated_numbers(arr):
    # The data structure we will use to hold information as we loop over the array
    # will be a dictionary mapping the a number to the index of it's first appearance
    # or -1 if the first appearance has been removed.
    # The possible states are as follows:
    # - If the number does not exist in the dictionary then it hasn't been seen yet
    # - If the number is in the dictionary and is mapped to a non-negative number then
    #   we've seen it exaclty once and the mapped number is the index of the one we've
    #   ween in the array
    # - If the number is in the dictionary and is mapped to -1 then it's been seen more
    #   than once and the orignal number has been removed from the array already
    seen_numbers = {}
    i = 0
    while i < len(arr):
        current_number = arr[i]
        if arr[i] in seen_numbers:
            if seen_numbers[current_number] is -1:
                # We've seen the number at least twice before, just remove this one
                arr = arr[0:i] + arr[i+1:]
                # Don't forget to change the iterating index since we're modifying the array
                # out from under ourselves
                i-=1
            else:
                # We've seen the number exactly once before, remove this one and the first one
                # First remove the first instance of this number and decrement i
                arr = arr[0:seen_numbers[current_number]] + arr[seen_numbers[current_number]+1:]
                i-=1
                # Now remove the number we're looking at now. i should point to the correct index
                arr = arr[0:i] + arr[i+1:]
                i-=1
                # Lastly set the index in seen_numbers to -1 indicating we've already removed the
                # first instance of this number
                seen_numbers[current_number] = -1
        else:
            seen_numbers[current_number] = i
        i+=1
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

# A solution to problem.txt in Python with test cases :)
# To try this on your own simply delete the contents of string_compression and fill it in yourself

# This method requires a string. It returns a compressed string version of the input following the
# spec of the problem in problem.txt
def string_compression(string):
    # If the string is length 0 then we can return right away
    if len(string) is 0:
        return ""

    # We start off having seen at least one letter, as we know the string is not of length 0
    letter_count = 1
    previous_letter = string[0]
    compressed_string = ""

    # For every letter after the first (which we've already seen)...
    for letter in string[1:]:
        # ...if it's the same letter then just increment the count of that letter...
        if letter == previous_letter:
            letter_count+=1
        # ...otherwise store the previous letter plus the count on the compressed string and start keeping track
        # of a new letter
        else:
            compressed_string = compressed_string + previous_letter + str(letter_count)
            letter_count = 1
            previous_letter = letter

    # We need to append the last letter and it's count before we return
    compressed_string = compressed_string + previous_letter + str(letter_count)

    return compressed_string

def run_single_test(test_number, input, expected):
    output = string_compression(input)
    if output == expected:
        print("Test " + str(test_number) + " PASSED")
    else:
        print("Test " + str(test_number) + " FAILED: expected " + expected + " but got " + output)

def run_tests():
    # Test 1: simple string
    run_single_test(1, "aaaabbb", "a4b3")

    # Test 2: empty string
    run_single_test(2, "", "")

    # Test 3: single character
    run_single_test(3, "a", "a1")

    # Test 4: multiple single characters
    run_single_test(4, "abcdefg", "a1b1c1d1e1f1g1")

    # Test 5: a more complex string
    run_single_test(5, "aaaaaaaabcdddeeeeefeeeeeefeeeeeggggggabc", "a8b1c1d3e5f1e6f1e5g6a1b1c1")

# Finally run the tests to see how we did
run_tests()
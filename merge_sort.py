def merge(left, right):
    if len(left) == 0:
        return right
    if len(right) == 0:
        return left

    result = []
    index_left, index_right = 0, 0

    # Preallocate result list size to avoid multiple resizing operations
    result_size = len(left) + len(right)
    result = [None] * result_size
    index_result = 0

    # Merge the two arrays
    while index_left < len(left) and index_right < len(right):
        if left[index_left] <= right[index_right]:
            result[index_result] = left[index_left]
            index_left += 1
        else:
            result[index_result] = right[index_right]
            index_right += 1
        index_result += 1

    # If there are remaining elements in either left or right,
    # append them all at once (slicing avoids multiple appends)
    if index_left < len(left):
        result[index_result:] = left[index_left:]
    if index_right < len(right):
        result[index_result:] = right[index_right:]

    return result

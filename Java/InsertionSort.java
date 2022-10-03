//InsertionSort

class InsertionSort {
  public static void main(String[] args) {
    int[] arr = new int[10];

    for (int i = 0; i < arr.length; i++) {
      arr[i] = (int) (Math.random() * 15);
    }

    insertionSort(arr);

    for (int i = 0; i < arr.length; i++) {
      System.out.println(arr[i]);
    }
  }

  public static void insertionSort(int[] array) {
    for (int i = 1; i < array.length; i++) {
      int current = array[i];
      int j = i - 1;
      while (j >= 0 && current < array[j]) {
        array[j + 1] = array[j];
        j--;
      }
      array[j + 1] = current;
    }
  }
}

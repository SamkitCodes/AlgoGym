import java.util.Iterator;

public class DynamicArray<T> implements Iterable<T> {

    private T[] arr; // Array to store the data
    private int length = 0; // The current elements in the array
    private int capacity = 0; // The total current capacity of the array

    /**
     * This is a default constructor with no parameters. It calls the parameterized constructor with a capacity of 16
     */
    public DynamicArray() { this(16); }

    /**
     * This is a constructor which creates an array of a specific size (greater than or equal to zero).
     * @param capacity The size of the array
     */
    public DynamicArray(int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity needs to be greater than 0: " + capacity);
        }
        this.capacity = capacity;
        arr = (T[]) new Object[capacity];
    }

    /**
     * Returns the number of elements currently stored in the array.
     *
     * @return The number of elements present in the array
     */
    public int size(){
        return length;
    }

    /**
     * Checks if the array is empty or not
     *
     * @return True if the dynamic array is empty, false otherwise
     */
    public boolean isEmpty(){
        return (this.size() == 0);
    }

    /**
     * Returns an element from the dynamic array from a specified index
     *
     * @param index Position of the element
     * @return element present on the index
     * @throws ArrayIndexOutOfBoundsException if the index is out of range
     *
     */
    public T get(int index){
        if (index < 0 || index >= arr.length) {
            throw new IndexOutOfBoundsException("Index out of bounds: " + index);
        }
        return arr[index];
    }

    /**
     * Set value of a particular index of dynamic array
     *
     * @param index the position of element to update
     * @param element The new value to be set at the specified index
     * @throws ArrayIndexOutOfBoundsException if the index is out of range
     */
    public void set(int index, T element){
        if (index < 0 || index >= arr.length) {
            throw new IndexOutOfBoundsException("Index out of bounds: " + index);
        }
        arr[index] = element;
    }

    /**
     * Clear all the elements from the array
     */
    public void clear(){
        for(int i = 0; i < length; i++){
            arr[i] = null;
        }
        length = 0;
    }

    /**
     * Adds a new element to the end of the dynamic array;
     *
     * @param element The value to be added
     */
    public void add(T element){

        // Doubling the capacity of the dynamic array if there is no space to add any new element
        if((length + 1) >= capacity){
            if(capacity == 0){
                capacity = 1;
            }
            else{
                capacity *= 2;
            }

            T[] new_dyArray = (T[]) new Object[capacity];
            for(int i = 0; i < length; i++){
                new_dyArray[i] = arr[i];
            }

            arr = new_dyArray;
        }

        arr[length] = element;
        length++;

    }

    /**
     *  Removes the element from the specified index and return it
     *
     * @param index The index from where the element has to be removed
     * @return The element which is removed
     */
    public T removeAt(int index){
        if( (index >= length) || (index < 0) ){
            throw new IndexOutOfBoundsException();
        }

        T data = arr[index];

        T[] new_arr = (T[]) new Object[length - 1];
        for(int i = 0, j = 0; i < length; i++, j++){

            if(i == index){
                j--;
            }else{
                new_arr[j] = arr[i];
            }

        }

        arr = new_arr;

        length--;
        capacity = length;
        return data;
    }

    /**
     * This method finds the index of the element specified if present. If no such element exists then it returns -1.
     *
     * @param obj The element which needs to be found in the dynamic array.
     * @return The index of the element
     */
    public int indexOf(Object obj){

        for(int i = 0; i < length; i++){
            if(obj == null){
                if(arr[i] == null){
                    return i;
                }
            }else{
                if(obj.equals(arr[i])){
                    return i;
                }
            }
        }

        return -1;
    }

    /**
     * Finds a object if present in the array and then remove it
     *
     * @param obj The element which needs to be found
     * @return True if the object was present and removed, false otherwise
     */
    public boolean remove(Object obj){

        int index = indexOf(obj);
        if(index == -1){
            return false;
        } else{
          removeAt(index);
          return true;
        }
    }

    /**
     * Checks if the specified object is present in the array.
     *
     * @param obj the object to search for in the array
     * @return True if the object is found in the array, false otherwise
     */
    public boolean contains(Object obj){
        if(indexOf(obj) == -1){
            return false;
        }

        return true;
    }




    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            int index = 0;

            @Override
            public boolean hasNext() {
                return index < length;
            }

            @Override
            public T next() {
                return arr[index++];
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }

        };
    }


    @Override
    public String toString() {
        if (length == 0) return "[]";
        else {
            StringBuilder sb = new StringBuilder(length).append("[");
            for (int i = 0; i < length - 1; i++) sb.append(arr[i] + ", ");
            return sb.append(arr[length - 1] + "]").toString();
        }
    }
}

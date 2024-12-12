import java.util.ArrayList;
import java.util.Iterator;

public class Queue<T> implements Iterable<T> {

    private ArrayList<T> list = new ArrayList<>();

    // Default empty constructor
    public Queue() {}

    // Constructor with an initial element
    public Queue(T element) {
        enqueue(element);
    }

    // Add an element to the end of the queue
    public void enqueue(T element) {
        list.add(element);
    }

    // Remove and return the first element in the queue
    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty!");
        }
        return list.remove(0); // Remove and return the first element
    }

    // Check if the queue is empty
    public boolean isEmpty() {
        return list.isEmpty();
    }

    // Get the size of the queue
    public int size() {
        return list.size();
    }

    // Iterator to iterate over the elements
    @Override
    public Iterator<T> iterator() {
        return list.iterator();
    }
}

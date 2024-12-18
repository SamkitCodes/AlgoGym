import java.util.Iterator;
import java.util.NoSuchElementException;

public class DoubleLinkedList<T> implements Iterable<T> {

    // Node class to represent a node in the doubly linked list
    private static class Node<T> {
        T data;
        Node<T> prev, next;

        public Node(T data, Node<T> prev, Node<T> next) {
            this.data = data;
            this.prev = prev;
            this.next = next;
        }
    }

    private Node<T> head; // Head of the list
    private Node<T> tail; // Tail of the list
    private int size;     // Size of the list

    // Add a new element at the end of the list
    public void addLast(T data) {
        Node<T> newNode = new Node<>(data, tail, null);
        if (tail != null) {
            tail.next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    // Add a new element at the beginning of the list
    public void addFirst(T data) {
        Node<T> newNode = new Node<>(data, null, head);
        if (head != null) {
            head.prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        size++;
    }

    // Remove the first element
    public T removeFirst() {
        if (head == null) throw new NoSuchElementException("List is empty");
        T data = head.data;
        head = head.next;
        if (head != null) {
            head.prev = null;
        } else {
            tail = null;
        }
        size--;
        return data;
    }

    // Remove the last element
    public T removeLast() {
        if (tail == null) throw new NoSuchElementException("List is empty");
        T data = tail.data;
        tail = tail.prev;
        if (tail != null) {
            tail.next = null;
        } else {
            head = null;
        }
        size--;
        return data;
    }

    // Check if the list contains a specific element
    public boolean contains(T data) {
        for (T item : this) {
            if ((data == null && item == null) || (data != null && data.equals(item))) {
                return true;
            }
        }
        return false;
    }

    // Get the size of the list
    public int size() {
        return size;
    }

    // Check if the list is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Iterate over the list using the Iterable interface
    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private Node<T> current = head;

            @Override
            public boolean hasNext() {
                return current != null;
            }

            @Override
            public T next() {
                if (current == null) throw new NoSuchElementException();
                T data = current.data;
                current = current.next;
                return data;
            }
        };
    }

    // Print the list
    public void printList() {
        for (T data : this) {
            System.out.print(data + " <-> ");
        }
        System.out.println("null");
    }

}

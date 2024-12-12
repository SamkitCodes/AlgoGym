import java.util.Iterator;
import java.util.LinkedList;

public class Stack<T> implements Iterable<T> {
    
    private LinkedList<T> list = new LinkedList<T>();

    public int size(){
        return list.size();
    }

    public boolean isEmpty(){
        return size() == 0;
    }

    public void push(T data){

        list.addLast(data);
    }

    public T pop() {
        if (isEmpty()) throw new java.util.EmptyStackException();
        return list.removeLast();
      }

      public T peek() {
        if (isEmpty()) throw new java.util.EmptyStackException();
        return list.peekLast();
      }


    @Override
    public Iterator<T> iterator() {
        return list.iterator();    
    }

    
}

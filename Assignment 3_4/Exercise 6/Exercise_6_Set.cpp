#include "stack_class.h"

template <typename Object>
class Set {
private:
    Stack<Object> stack;

public:
    /*      Insert adds ellement to stack.      */
    void insert(const Object& element) {
        // Checks if the element is not already in the set.
        if (!contains(element)) {
            stack.push(element);
        }
    }
    /*       Remove deletes                     */
    void remove(const Object& element) {
        // Creating a temporary stack to hold elements we want to keep
        Stack<Object> tempStack;

        //  Elements that are not equal to the one to being deleted is being stored here.
        while (!stack.empty()) {
            Object current = stack.top();
            stack.pop();
            if (current != element) {
                tempStack.push(current);
            }
        }

        // Kept elements that have not been deleted is pushed back in the original
        while (!tempStack.empty()) {
            Object current = tempStack.top();
            tempStack.pop();
            stack.push(current);
        }
    }

    /*      Contains is our search           */
    bool contains(const Object& element) {
        Stack<Object> tempStack;
        bool found = false;

        // Temporary storing while looking for the element in search
        while (!stack.empty()) {
            Object current = stack.top();
            stack.pop();
            tempStack.push(current);

            if (current == element) {
                found = true;
                break;
            }
        }

        // Puts elements back in the original stack
        while (!tempStack.empty()) {
            Object current = tempStack.top();
            tempStack.pop();
            stack.push(current);
        }

        return found;
    }

    // Returns size of Stack
    int size() const {
        return stack.size();
    }

    // if empty will return empty
    bool is_empty() const {
        return stack.empty();
    }
};

int main() {
    Set<int> TestSet;

    // Insert elements
    TestSet.insert(1);
    TestSet.insert(2);
    TestSet.insert(3);

    // Check if elements are present
    std::cout << "Contains 2? " << TestSet.contains(2) << std::endl; // Should print 1 (true)
    std::cout << "Contains 4? " << TestSet.contains(4) << std::endl; // Should print 0 (false)

    // Remove an element
    TestSet.remove(2);

    // Check size and emptiness
    std::cout << "Size of set: " << TestSet.size() << std::endl;    // Should print 2
    std::cout << "Is set empty? " << TestSet.is_empty() << std::endl; // Should print 0 (false)

    // Remove the remaining elements
    TestSet.remove(1);
    TestSet.remove(3);

    // Check size and emptiness again
    std::cout << "Size of set: " << TestSet.size() << std::endl;    // Should print 0
    std::cout << "Is set empty? " << TestSet.is_empty() << std::endl; // Should print 1 (true)

    return 0;
}

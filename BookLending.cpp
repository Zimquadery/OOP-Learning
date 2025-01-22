#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    bool isAvailable;

public:
    Book(string t, string a) : title(t), author(a), isAvailable(true) {}

    void borrowBook()
    {
        if (isAvailable)
        {
            isAvailable = false;
            cout << "The book \"" << title << "\" has been borrowed." << '\n';
        }
        else
        {
            cout << "The book \"" << title << "\" is not available." << '\n';
        }
    }

    void returnBook()
    {
        isAvailable = true;
        cout << "The book \"" << title << "\" has been returned." << '\n';
    }

    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    bool getAvailability()
    {
        return isAvailable;
    }
};

class Member
{
private:
    string name;
    int memberID;
    Book* borrowedBooks[10];
    int borrowedCount;

public:
    Member(string n, int id) : name(n), memberID(id), borrowedCount(0) {}

    void borrow(Book &book)
    {
        if (borrowedCount < 10)
        {
            book.borrowBook();
            if (!book.getAvailability())
            {
                borrowedBooks[borrowedCount++] = &book;
            }
        }
        else
        {
            cout << "Cannot borrow more than 10 books." << '\n';
        }
    }

    void returnBook(Book &book)
    {
        book.returnBook();
        for (int i = 0; i < borrowedCount; ++i)
        {
            if (borrowedBooks[i] == &book)
            {
                for (int j = i; j < borrowedCount - 1; ++j)
                {
                    borrowedBooks[j] = borrowedBooks[j + 1];
                }
                borrowedBooks[--borrowedCount] = nullptr;
                break;
            }
        }
    }

    void getBorrowingHistory()
    {
        cout << name << " has borrowed the following books:" << '\n';
        for (int i = 0; i < borrowedCount; ++i)
        {
            cout << "- " << borrowedBooks[i]->getTitle() << " by " << borrowedBooks[i]->getAuthor() << '\n';
        }
    }
};

int main()
{
    Book book1("The Great Gatsby", "F. Scott Fitzgerald");
    Book book2("1984", "George Orwell");

    Member member1("Alice", 1);

    member1.borrow(book1);
    member1.borrow(book2);

    member1.getBorrowingHistory();

    member1.returnBook(book1);
    member1.getBorrowingHistory();

    return 0;
}
function Library() {
  this.books = [];

  this.addBook = (book) => {
    this.books.push(book);
  };

  this.listBooks = () => {
    for (let i = 0; i < this.books.length; i++) {
      console.log(
        `Book ${i + 1}: ${this.books[i].title} by ${this.books[i].author} (${
          this.books[i].publishYear
        })`
      );
    }
  };

  this.getBookByTitle = (title) => {
    return this.books.filter((book) => book.title.includes(title));
  };
}

function Book(title, author, publishYear) {
  if (!title || !author || !publishYear) {
    throw new Error("Missing required fields");
  }

  this.title = title;
  this.author = author;
  this.publishYear = publishYear;
}

const library = new Library();
const book1 = new Book("The Alchemist", "Paulo Coelho", 1988);
const book2 = new Book("The Little Prince", "Antoine de Saint-Exupéry", 1943);
const book3 = new Book("The Hobbit", "J.R.R. Tolkien", 1937);

library.addBook(book1);
library.addBook(book2);
library.addBook(book3);

library.listBooks();

console.log(library.getBookByTitle("Alchemist"));

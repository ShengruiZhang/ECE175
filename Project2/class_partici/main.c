#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



#include <stdlib.h>
//____________________   //to use malloc and calloc


typedef struct pub_struct {
	char *name;
	char *phone;
} publisher;

typedef struct book_struct {
	char *title;		//book title
	char *auth;		//author
	int code;		//id
	publisher *pub_ptr;
} book;

int main(void) {
	book *books_ptr;
	char str[100];
	int i, num, code_entered;
	char ans;

	printf("Enter number of books: ");
	scanf("%d", &num);
	getchar();  //to get newline char from the 
				//above scanf before fgets used below

	books_ptr = (book *)malloc(num * sizeof(book));
	//asking a user to enter information for each book
	for (i = 0; i < num; i++) {
		printf("Title: ");
		fgets(str, 100, stdin);
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = 0;

		books_ptr[i].title = (char *)
			malloc((strlen(str) + 1) * sizeof(char));

		strcpy(books_ptr[i].title, str);






		printf("Author: ");
		fgets(str, 100, stdin);
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = 0;

		books_ptr[i].auth = (char *)calloc(sizeof(char), strlen(str) + 1);

		strcpy(books_ptr[i].auth, str);





		printf("Code: ");
		scanf("%d", &books_ptr[i].code);
		getchar(); //to get newline char from above

				   //allocate memory for pub_ptr of book with index [i]

		//__________________________________
		books_ptr->pub_ptr = (publisher*)malloc(sizeof(publisher));






		printf("Publisher Name: ");
		fgets(str, 100, stdin);
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = 0;

		books_ptr[i].pub_ptr= (char *)malloc((strlen(str) + 1) * sizeof(char));

		strcpy(books_ptr[i].pub_ptr->name, str);







		printf("Publisher Phone (enter xxxxxxxxxx): ");
		fgets(str, 100, stdin);
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = 0;

		books_ptr[i].pub_ptr->phone = (char *)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(books_ptr[i].pub_ptr->phone, str);

	}  // for (i = 0; i < num; i++){

	while (1) {

		printf("\nEnter code to search: ");
		scanf("%d", &code_entered);
		getchar();

		//compare whether the code entered is in   
		//database, if yes, print title, author, publisher   
		//name
		for (i = 0; i < num; i++) {
			if (books_ptr->code == code_entered) {
				printf("%s by %s, published by %s", books_ptr->title,
					books_ptr->auth,
					books_ptr->pub_ptr);
				break;
			}
		}
		if (books_ptr->code != code_entered) {
			printf("Code %d is not in the database",
				code_entered);
		}
		printf("\nSearch again (q to quit)?: ");
		scanf("%c", &ans);
		if (ans == 'q' || ans == 'Q')
			break;
	}

	for (i = 0; i < num; i++) {
		free((*books_ptr[i].pub_ptr).phone);
		free((*books_ptr[i].pub_ptr).name);
		free(books_ptr[i].title);
		free(books_ptr[i].auth);
		free(books_ptr[i].pub_ptr);
	}
	free(books_ptr);

	return 0;
} //main


  /* book examples
  Enter number of books: 4
  Title: To Kill a Mockingbird
  Author: Harper Lee
  Code: 12345
  Publisher Name: Warner Books, Inc.
  Publisher Phone (enter xxxxxxxxxx): 8009876543
  Title: War and Peace
  Author: Leo Tolstoy
  Code: 18691
  Publisher Name: The Russian Messenger
  Publisher Phone (enter xxxxxxxxxx): 8001234567
  Title: The Adventures of Huckleberry Finn
  Author: Mark Twain
  Code: 18851
  Publisher Name: Amazon Classics
  Publisher Phone (enter xxxxxxxxxx): 9992804331
  Title: Harry Potter and the Sorcerer's Stone
  Author: J.K. Rowling
  Code: 20011
  Publisher Name: Bloomsbury
  Publisher Phone (enter xxxxxxxxxx): 2124915300


  Enter code to search: 18691
  War and Peace by Leo Tolstoy, published by The Russian Messenger
  Search again (q to quit)?: y

  Enter code to search: 18691
  War and Peace by Leo Tolstoy, published by The Russian Messenger
  Search again (q to quit)?: y

  Enter code to search: 18851
  The Adventures of Huckleberry Finn by Mark Twain, published by Amazon Classics
  Search again (q to quit)?: Q

  */
 #include<stdio.h>
 #include<string.h>
 struct  record
  {
   char author[20];
   char title[30];
   float price;
   struct
  {
   char month[10];
   int year;
  }
  date;
  char publisher[10];
  int quantity;
 };
 
 int texts(struct record table[],char s1[],char s2[],int m);
 void get(char string[] );
 void main()
 {
  char title[30], author[20];
  int  index, no_of_records;
  char response[10], quantity[10];
  struct record book[] =
 {
 {"apj abdul kalam","wings on fire",220.00,"july",1999,"Hayden",15},
 {"walter isaacson","Einsten his life and universe",560.00,"januray",2005,"PHI",10},
 {"stanlee","marvel cinematic universe",30.00,"may",1945,"MARVEL",50},
 {"ashlee vance","elon musk",60.00,"march",2014,"wilson",30}
 };

 no_of_records = sizeof(book)/ sizeof(struct record);
 do
 {
  printf("\n Enter title and author name as per the list");
  printf("\n Title: ");
  get(title);
  printf(" Author: ");
  get(author);
  index = texts(book, title, author, no_of_records);
  if(index != -1)     /*  Book found  */
 {
  printf(" **DETAILS OF BOOK** \n Author- %s \n Title- %s \n per book rupess- %.2f \n Month- %s \n Year- %d \n Publisher- %s\n",
  book[index].author,
  book[index].title,
  book[index].price,
  book[index].date.month,
  book[index].date.year,
  book[index].publisher);
  
  printf(" Enter number of copies:");
  get(quantity);
  if( atoi(quantity) < book[index].quantity)
  
  printf(" **Cost of %d %s book copies = %.2f**\n", atoi(quantity), 
  book[index].title,book[index].price * atoi(quantity));
  else
  
  printf(" **Required copies not in stock**\n");
 }
  else
  printf(" **Book not in list**\n");
  printf("\n **Do you want any other book?** \n (YES / NO):");
  get(response);
 }
  while(response[0] == 'Y' || response[0] == 'y');
  printf(" **Thank you and please visit again.**\n");
 }
  void get(char string[] )
 {
  char  c;
  int  i = 0;
  do
 {
  c = getchar();
  string[i++] = c;
 }
  while(c != '\n');
  string[i-1] = '\0';
 }

  int texts(struct record table[],char s1[],char s2[],int m)
 {
  int  i;
  for(i = 0; i < m;  i++)
  if(strcmp(s1, table[i].title) == 0  && strcmp(s2, table[i].author) == 0)
  return(i);           // book found
  return(-1);         //book not found
}

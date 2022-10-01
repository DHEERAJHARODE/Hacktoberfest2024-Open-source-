# Object Oriented Programming Concepts focusing on Real world examples
The main aim of OOP is to bind together the data and the functions that operate on them so that no other part of the code can access this data except that function.

- 4 Pillar of OOPs:
1. Encapsulation
2. Abstraction
3. Polymorphism
4. Inheritance 

<ins>ENCAPSULATION</ins> : 
Encapsulation is defined as binding together the data and the functions under a single unit called class and it helps in data hiding.
- Suppose you go to an automatic cola vending machine and request for a cola. The machine processes your request and gives the cola.  
- Here automatic cola vending machine is a **class**. It contains both data i.e. Cola can and operations i.e. service mechanism and they are wrapped/integrated under a single unit Cola Vending Machine. This is called **Encapsulation**.  
- You can interact with cola can only through service mechanism. You cannot access the details about internal data like how much cans it contains, mechanism etc. This is **Data Hiding**.    
Resource used : [link](https://qr.ae/pG3bVF)

<ins>ABSTRACTION</ins> : 
Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.  
- A man is driving a car, the man only knows that pressing the accelerators will increase the speed of car or applying brakes will stop the car but he does not know about how on pressing accelerator the speed is actually increasing, he does not know about the inner mechanism of the car or the implementation of accelerator, brakes etc in the car. This is what **abstraction** is.

<ins>POLYMORPHISM</ins> : 
The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. 
- A real-life example of polymorphism, a person at the same time can have different characteristics. Like a man at the same time is a father, a husband, an employee. So the same person posses different behavior in different situations. This is called **polymorphism**.
- In C++ polymorphism is mainly divided into two types:
  - Compile time Polymorphism  
  - Runtime Polymorphism
- Compile time polymorphism: This type of polymorphism is achieved by function overloading or operator overloading.
  - **Operator Overloading**: The process of making an operator to exhibit different behaviours in different instances is known as operator overloading. For eg, we can make the operator (‘+’) for string class to concatenate two strings. We know that this is the addition operator whose task is to add two operands. So a single operator ‘+’ when placed between integer operands , adds them and when placed between string operands, concatenates them.
  - **Function Overloading**: When there are multiple functions with same name but different parameters then these functions are said to be overloaded. Functions can be overloaded by change in number of arguments or/and change in type of arguments.
- Run time polymorphism: This type of polymorphism is achieved by Function Overriding.
  - **Function overriding**: in C++ is a feature that allows us to use a function in the child class that is already present in its parent class. The child class inherits all the data members, and the member functions present in the parent class.
- Real time example:
  - **OverLoading** : In C++, two or more functions can have the same name if the number and/or type of parameters are different, this is called function overloading. Thus, overloaded functions are functions that have the same name but different parameters.
    - There are a number of students studying in this world. There are some school students, for them study means to complete their homework in Few Subjects. And they are done. Their are some computer students like us, where study means coding, development, implementation work and daily learning something new. There are some medical guys, for them study means a lot of experiments on a number of objects and getting on new conclusions and many more. You see, We all are studying, learning, growing (doing same work ) but our requirements, output, working is different. That’s what Overloading is.
  - **OverRiding** : When a member function of a base class is redefined in its derived class with the same parameters and return type, it is called function overriding in C++. Now, if we use an object of the derived class to call this function, the function defined in the derived class is invoked. The base class function is said to be overridden.
    - Your father had a old but working bike which you got from him. You think the bike would be better just after some modifications like (painting, cleaning etc). And in this way, you have changed bike properties but bike’s requirements and output is still same just working is changed (more efficient). And That’s what OverRiding is.  
Resources used : [link](https://qr.ae/pG3gRM) , [link](https://techvidvan.com/tutorials/function-overloading-and-overriding-in-cpp/)

<ins>INHERITANCE</ins> :
The capability of a class to derive properties and characteristics from another class is called Inheritance.  
 - **Sub Class**: The class that inherits properties from another class is called Sub class or Derived Class.  
 - **Super Class**:The class whose properties are inherited by sub class is called Base Class or Super class. 
 - **Re-usability**: Inheritance supports the concept of “re-usability”, i.e. when we want to create a new class and there is already a class that includes some of the code that we want, we can derive our new class from the existing class. By doing this, we are reusing the fields and methods of the existing class.
- Types of Inheritance in C++  
  - Single Inheritance : 
In Single level inheritance, there is single base class & a single derived class i.e. - A base mobile features is extended by Samsung brand or Employee is the base class and Programmer is the derived class.
  - Multiple Inheritance : Parents are a good example of multiple inheritance. Each child has two parents—that’s just the way it is.
  - Hierarchial Inheritance : In this type of inheritance, multiple derived class would be extended from base class, it's similar to single level inheritance but this time along with Samsung, Nokia is also taking part in inheritance.
  - Multilevel Inheritance : In Multilevel inheritance, there is more than one single level of derivation. i.e. - After base features are extended by Samsung brand. Now Samsung brand has manufactured its new model with new added features or advanced OS like Android OS, v4.4.2 (kitkat). From generalization, getting into more specification.
  - Hybrid Inheritance : Single, Multilevel, & hierarchal inheritance all together construct a hybrid inheritance.  
Resource used : [link](https://www.c-sharpcorner.com/UploadFile/cda5ba/object-oriented-programming-with-real-world-scenario/)


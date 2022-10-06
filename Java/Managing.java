import java.util.*;

class Employee
{
    private String name, dep;
    private int id, sal;

    Employee(){}

    Employee(String name, String dep, int id, int sal)
    {
        this.name = name;
        this.dep = dep;
        this.sal = sal;
        this.id = id;
    }

    int salary()
    {
        return sal;
    }

    void display()
    {
        System.out.println("Name : " + name + ", Department : " + dep + ", ID : " + id + ", Salary : " + sal);
    }
}

class Manager extends Employee
{
    private int bonus;
    
    Manager(){}

    Manager(String name, String dep, int id, int sal, int bonus)
    {
        super(name, dep, id, sal);
        this.bonus = bonus;
    }
    
    void display()
    {
        super.display();
        System.out.println("Bonus : " + bonus);
    }
    
    void max_salary(Manager m[])
    {
        int max = 0, pos = 0;
        for(int i = 0; i < m.length; i++)
        {
            if((m[i].salary() + m[i].bonus) > max)
            {
                max = (m[i].salary() + m[i].bonus);
                pos = i;
            }
        }

        m[pos].display();
        System.out.println("Total Salary is : " + (m[pos].salary() + m[pos].bonus));
    }
}

class Managing
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);

        String name, dep;
        int id, sal, bonus;

        System.out.println("\nEnter Number of Managers :");
        int n = sc.nextInt();

        Manager marr[] = new Manager[n];

        for(int i = 0; i < n; i++)
        {
            System.out.print("\nFor Manager " + (i+1));
            System.out.println("\nEnter Name : ");
            name = sc.next() + sc.nextLine();
            System.out.println("Enter Department : ");
            dep = sc.next() + sc.nextLine();
            System.out.println("Enter ID : ");
            id = sc.nextInt();
            System.out.println("Enter Salary : ");
            sal = sc.nextInt();
            System.out.println("Enter Bonus : ");
            bonus = sc.nextInt();

            marr[i] = new Manager(name, dep, id, sal, bonus);
        }

        for(int i = 0; i < n; i++)
        {
            System.out.println("\nManager " + (i+1) + " :");
            marr[i].display();
        }

        System.out.println("\nManager with Highest Salary is :");
        Manager m = new Manager();
        m.max_salary(marr);
    }
}
import java.util.Scanner;

class Grade 
{
    int s;

    Grade(int score) 
    {
        s = score;
    }

    char letterGrade() 
    {
        if (s < 40)
            return 'F';
        else if (s >= 40 && s < 50)
            return 'D';
        else if (s >= 50 && s < 60)
            return 'C';
        else if (s >= 60 && s < 70)
            return 'B';
        else if (s >= 70 && s < 80)
            return 'A';
        else if (s >= 80 && s < 90)
            return 'E';
        else if (s >= 90 && s <= 100)
            return 'O';
        else
            return 'X';  // Default case for safety, though it should not occur
    }
}

class Demo 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);  // Corrected variable name
        System.out.println("Enter score:");
        int score = sc.nextInt();

        if (score < 0) 
        {
            
            System.out.println("Negative input invalid");
        } 
        else if (score > 100) 
        {
            System.out.println("Please provide Range 0-100");
        } 
        else 
        {
            Grade ob = new Grade(score);  // Corrected class name
            char g = ob.letterGrade();
            System.out.println("Grade is:");
            System.out.println(g);
        }
    }
}

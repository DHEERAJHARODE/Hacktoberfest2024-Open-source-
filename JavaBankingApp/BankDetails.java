// I have explained each of the lines of the code in "Odia Language".
//Java ra Scanner Class Import Karili Keyboard ru input naba pain
import java.util.Scanner;
//BankDetails naa ra gote class bneili joutaki amara main class
class BankDetails {
//    Tinta instance variable bneichi joutaki mu private karichi. Ya maane yara access mu only eii class bhitare he kari paribi au kounasi class kimba package re kari paribini
    private String accno;
    private String name;
    private String acc_type;
    private long balance;
//    Scanner class ra gote object bneili
    Scanner sc = new Scanner(System.in);
    //Gote constructor bneili joutare account open karibar method lekhichi au etara return type aame void rakhichu. Yah maane aame khali input nouchu au method taku douchu. Aamaku kichi return darkar naahi amaku khali input nabar achhi.
    public void openAccount() {
//        Jou instance variables aame banei thilu aguru segulanka bhitare ebe mu data input neiki store karuchi
        System.out.print("Enter Account No: ");
        accno = sc.next();
        System.out.print("Enter Account type: ");
        acc_type = sc.next();
        System.out.print("Enter Name: ");
        name = sc.next();
        System.out.print("Enter Balance: ");
        balance = sc.nextLong();
    }
//    Ebe gote constructor baneilu aame jooutare jo method ta achhi seta khali print karauchi ama input. Aame jou openAccount constructor baneiki input neithilu segula sbu print karauchu.
//    openAccount auu showAccount ei di ta example hele non-parameterised constructor ra
    public void showAccount() {
        System.out.println("Name of account holder: " + name);
        System.out.println("Account no.: " + accno);
        System.out.println("Account type: " + acc_type);
        System.out.println("Balance: " + balance);
    }
//    Ebe aau gote constructor baneilu aame jouta re jo method ta achhi taku use kriki aame cash deposit kemiti kariba seta lekhiba code re
    public void deposit() {
//        Gote variable baneili. Note karibu, eta instance variable nuhe. Kainki nuhe? dekh instance variable tanku kahanti goutare aame kichi value dei na thiba aguru and sei variable ta kichi method re nathiba. "long amt" eii variable ta dekh "deposit" constructor bhitare achhi ta maane eta instance variable nuhe
        long amt;
        System.out.println("Enter the amount you want to deposit: ");
//        Input nelu
        amt = sc.nextLong();
//        Ebe gote logic delu aame. Kn? Je deopit money taku balance sahita add karidiya au phir jo value ta calculate heiki asiba seta "balance" re store kari diya
        balance = balance + amt;
    }
    //method to withdraw money
    public void withdrawal() {
//        Etare gote jinsa dekh, mu same variable name "amt" ku ethire use krichi but etare error delani. Kainki? default access modifier use heichi.. jyadi mu "public long amt" emiti lekhi thanti then error dei thanta
        long amt;
        System.out.println("Enter the amount you want to withdraw: ");
        amt = sc.nextLong();
//        Logic lekhilu.. Je jyadi mora balance withdrawal amount ru besi ta balance ru withdrawal amount taku minus kri ddia au jou value ta siba seta store karidia balance re
        if (balance >= amt) {
            balance = balance - amt;
            System.out.println("Balance after withdrawal: " + balance);

//            else use kriki lekhichi jyadi balance withdrawal amount ru kam achhi ta print kar balancce low
        } else {
            System.out.println("Your balance is less than " + amt + "\tTransaction failed...!!" );
        }
    }
    //method to search an account number
//    Gote logic lekhili account number ama array re achi ki nahi.. Suppose aame ei program ta chaleilu, au amaku bht sara input milila.. For example, tu nija details delu input krilu, mu karili. Au amaku ebe gote feature darkar je amaku search kribar achhi account gote. Bhabine mte search karibar achhi mo account ta ta mu kemiti karibi? ethi pain mu ei method ta lekhili joutaru aame account ta search kari pariba

//    Parameterized constructor bneichi jahara return type hela boolean.. ya maane? siye true kimba false return kariba
    public boolean search(String ac_no) {
//        Ethi logic deichi je, mu jou account ta search karichi seta exist karuchi ki nahi.. Maane gote case bhab, tu aaji nija details enter karilu, tora sabu details array re store hela.. Phir tu kali aasilu, ta tu kn nija details phirse input karibu? Na!! obviously. Sethi pain tu nija account nmbr search karibu au jyadi to account exist kare array re ta to details tate show kariba




        if (accno.equals(ac_no)) {
            showAccount();
            return (true);
        }
        return (false);
    }
}



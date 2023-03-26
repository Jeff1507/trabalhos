import java.util.Scanner;
import java.util.Random;

public class jokenpo {

    public static void main(String[] args) {
        int opUser, opPc, i, win=0, lose=0;
        int pedra=0, papel=0, tesoura=0;
        int pedraPc=0, papelPc=0, tesouraPc=0;
        Scanner scan=new Scanner (System.in);
        Random rand=new Random();

        for(i=0; i<3; i++)
        {
            System.out.println("(1) para Pedra");
            System.out.println("(2) para Papel");
            System.out.println("(3) para Tesoura");
            System.out.print("> ");
            opUser=scan.nextInt();

            if(opUser==1)
            {
                pedra++;
            }
            else if(opUser==2)
            {
                papel++;
            }
            else
            {
                tesoura++;
            }

            opPc=1+(rand.nextInt(3));
            //System.out.printf("\n%d", opPc);

            { 
                if(opPc==1)
                {
                    pedraPc++;
                }
                else
                {
                    if(opPc==2)
                    {
                    papelPc++;
                    }
                    else 
                    {
                    tesouraPc++;
                    }
                } 
            }
            if(opUser==opPc)
            {
                System.out.println("Empate!");
            }
            else if((opUser==1 && opPc==3) || (opUser==2 && opPc==1) || (opUser==3 && opPc==2))
            {
                System.out.println("Você venceu!");
                win++;
            }
            else
            {
                System.out.println("Você perdeu!");
                lose++;
            }
        }
        if(win>lose)
        {
            System.out.println("Parabens, você venceu o jogo!");
        }
        else
        {
            if(win==lose)
            {
                System.out.println("O jogo empatou!");
            }
            else
            {
                System.out.println("Que pena, você perdeu o jogo!");
            }
        }
        System.out.println("Jogador");
        System.out.println("Pedra = " +pedra+ "\tPapel = " +papel+ "\tTesoura = " +tesoura);
        System.out.println();
        System.out.println("Computador");
        System.out.println("Pedra = " +pedraPc+ "\tPapel = " +papelPc+ "\tTesoura = " +tesouraPc);

    }
}

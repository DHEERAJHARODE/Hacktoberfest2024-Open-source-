import java.awt.*;
import java.awt.event.*;

public class LaughingMachine {
    public static void main(String[] args) {
        Frame frame = new Frame("Laughing Machine");
        frame.setSize(400, 200);
        frame.setLayout(new BorderLayout());

        Label label = new Label("Press any key to make the Laughing Machine laugh!");
        frame.add(label, BorderLayout.NORTH);

        TextArea textArea = new TextArea();
        frame.add(textArea, BorderLayout.CENTER);

        frame.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                textArea.append("HAHAHAHAHAHA! ");
            }
        });

        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        frame.setVisible(true);
    }
}

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Random;


public class GameField extends JPanel implements ActionListener{
    private final int SIZE = 425;
    private final int DOT_SIZE = 16;
    private final int ALL_DOTS = 400;
    private Image dot;
    private Image Ore;
    private Image Goblin;
    private int OreX;
    private int OreY;
    private int GoblinX;
    private int GoblinY;
    private int[] x = new int[ALL_DOTS];
    private int[] y = new int[ALL_DOTS];
    private int dots;
    private Timer timer;
    private boolean left = false;
    private boolean right = true;
    private boolean up = false;
    private boolean down = false;
    private boolean inGame = true;


    public GameField(){
        setBackground(Color.gray);
        loadImages();
        initGame();
        addKeyListener(new FieldKeyListener());
        setFocusable(true);

    }

    public void initGame(){
        dots = 1;
        for (int i = 0; i < dots; i++) {
            x[i] = 48 - i*DOT_SIZE;
            y[i] = 48;
        }
        timer = new Timer(200,this);
        timer.start();
        createOre();
    }

    public void createOre(){
    	OreX = new Random().nextInt(20)*DOT_SIZE;
    	OreY = new Random().nextInt(20)*DOT_SIZE;
    	GoblinX = new Random().nextInt(20)*DOT_SIZE;
        GoblinY = new Random().nextInt(20)*DOT_SIZE;
    }

    public void loadImages(){
        ImageIcon iia = new ImageIcon("Ore.png");
        Ore = iia.getImage();
        ImageIcon iid = new ImageIcon("Dwarf.png");
        dot = iid.getImage();
        ImageIcon iic = new ImageIcon("Goblin.png");
        Goblin = iic.getImage();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if(inGame){
            g.drawImage(Ore,OreX,OreY,this);
            for (int i = 0; i < dots; i++) {
                g.drawImage(dot,x[i],y[i],this);
            }
            g.drawImage(Goblin,GoblinX,GoblinY,this);
            for (int i = 0; i < dots; i++) {
                g.drawImage(dot,x[i],y[i],this);
            }
        } 
        else{
            String str = "Buddy, that's game over(";
            //Font f = new Font("Arial",20,Font.BOLD);
            g.setColor(Color.red);
           // g.setFont(f);
            g.drawString(str,125,SIZE/2);
        }
    }

    public void move(){
        if(left){
            x[0] -= DOT_SIZE;
        }
        if(right){
            x[0] += DOT_SIZE;
        } 
        if(up){
            y[0] -= DOT_SIZE;
        } 
        if(down){
            y[0] += DOT_SIZE;
        }
    }

    public void checkOre(){
        if(x[0] == OreX && y[0] == OreY){
            createOre();
        }
        if(x[0] == GoblinX && y[0] == GoblinY) {
        	inGame = false;
        }
    }

    public void checkCollisions(){

        if(x[0]>SIZE){
            inGame = false;
        }
        if(x[0]<0){
            inGame = false;
        }
        if(y[0]>SIZE){
            inGame = false;
        }
        if(y[0]<0){
            inGame = false;
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(inGame){
            checkOre();
            checkCollisions();
            move();

        }
        repaint();
    }

    class FieldKeyListener extends KeyAdapter{
        @Override
        public void keyPressed(KeyEvent e) {
            super.keyPressed(e);
            int key = e.getKeyCode();
            if(key == KeyEvent.VK_LEFT && !right){
                left = true;
                up = false;
                down = false;
            }
            if(key == KeyEvent.VK_RIGHT && !left){
                right = true;
                up = false;
                down = false;
            }

            if(key == KeyEvent.VK_UP && !down){
                right = false;
                up = true;
                left = false;
            }
            if(key == KeyEvent.VK_DOWN && !up){
                right = false;
                down = true;
                left = false;
            }
        }
    }


}

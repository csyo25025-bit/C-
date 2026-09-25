// WinHello.java

import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JFrame;

public class WinHello extends JFrame {
	int called=0;
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public static void main(String[] args) {
		WinHello w = new WinHello();
		w.setSize(400, 80); //Window のサイズをセット
		w.setTitle("Hello, window!"); // Window のタイトルをセット
		w.setVisible(true); //表示する
	}
	
	public void paint(Graphics g) {
		// To do: 文字の位置を変える，文字の大きさを変える，文字の種類を変える，文字の色を変える，文字以外も表示してみる．．．
		Font font = new Font("", Font.BOLD,36);
		g.setFont(font);
		g.drawString("Hello, world!", 100, 60); // 文字列の表示
		System.out.println("paintが呼ばれました("+(++called)+"回目)");
	}
}
//ButtonMain2.java
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class ButtonMain2 extends JFrame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JButton btn;
	JLabel lb;
	int count=0;

	public static void main(String[] args) {
		ButtonMain2 w = new ButtonMain2();
		w.setVisible(true); //表示する
	}

	public ButtonMain2() {
		setSize(200, 200); //Window のサイズをセット
		setTitle("ButtonPressed?"); // Windowのタイトルをセット
		lb = new JLabel("0"); // テキストフィールド生成
		btn = new JButton("press me!"); // ボタン生成
		btn.addActionListener(this); // ボタンが押された時はこのクラスで処理
		add(lb, BorderLayout.NORTH); //　テキストフィールドを北(上)に配置
		add(btn, BorderLayout.CENTER); // ボタンを中央に配置
	}

	@Override
	public void actionPerformed(ActionEvent ae) {
		++count;//ボタンを押した回数
		lb.setText(Integer.toString(count));
	}
}
// ButtonMain.java
import java.awt.BorderLayout;
import java.awt.Button;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

// JFrame (window) クラスを継承した ButtonMain という名の公開(public)クラス
@SuppressWarnings("serial")
public class ButtonMain extends JFrame {

  // アプリケーション開始時に呼び出されるメソッド
  // 言語仕様で決められているので args 以外は固定 args でコマンドラインから引数を渡せる
  public static void main(String[] args) {
    // 自分自身のインスタンスをコンストラクト メモリ領域を確保して初期化
	  JButton btn = new JButton("press me!");
    // インスタンスの外側のサイズを200(横), 200(縦)　に設定
    w.setSize(200, 200); //Window のサイズをセット
    // ボタンのインスタンスをコンストラクト メモリ領域を確保して表示を press me! に初期化
    Button btn = new Button("press me!"); // ボタンを生成
    //w.add(btn); // ButtonMainのインスタンス w にボタンを配置
    JLabel lb = new JLabel("Label"); // ラベル生成
	//w.add(lb); //　ラベルを配置
	w.add(lb, BorderLayout.NORTH); //　ラベルを北(上)に配置
	w.add(btn, BorderLayout.CENTER); // ボタンを中央に配置
    w.setVisible(true); // ButtonMainのインスタンス w を表示
  }
}

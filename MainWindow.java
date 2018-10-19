package feedbackEvaluator;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Label;
import java.awt.Font;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JSeparator;

public class MainWindow {

	private JFrame frame;
	//Launch the Appliction
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainWindow window = new MainWindow();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	//Create the Application
	public MainWindow() {
		initialize();
	}

	//Initializing the contents of the Frame
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 442, 362);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		String[] teacherList = {
				"Ankita Shukla",
				"Aradhana Kumari",
				"Hukum Singh Rana",
				"Poonam Kainthura",
				"U Rajinikanth",
				"Pankaj Badoni",
				"Bhupendra Singh",
				"Sandeep Chaurasiya",
				"Anushree Shah",
				"Vishal Kaushik",
				"Gunjan Chhabra",
				"Niharika Singh",
				"Jatin Sethi",
				"Tripti Mishra",
				"Keshav Kaushik"
		};
		JComboBox teacherBox = new JComboBox(teacherList);
		teacherBox.setBounds(112, 63, 208, 22);
		
		JButton scoreButton = new JButton("Show Score");
		scoreButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(e.getSource() == scoreButton) {
					int index = teacherBox.getSelectedIndex();
					System.out.println("Index: "+index);
					frame.disable();
					ShowScore sc = new ShowScore(index);
				}
			}
		});
		scoreButton.setBounds(10, 275, 129, 37);
		
		JButton generateButton = new JButton("Generate Report");
		generateButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(e.getSource() == generateButton) {
					int index = teacherBox.getSelectedIndex();
					frame.disable();
					GenerateChart gc = new GenerateChart(index);
					GeneratePDF pdf = new GeneratePDF(gc.addressString, gc.addressPNG);
				}
			}
		});
		generateButton.setBounds(287, 275, 129, 37);
		
		
		Label welcomeLabel = new Label("WELCOME TO FEEDBACK EVALUATOR");
		welcomeLabel.setFont(new Font("Consolas", Font.PLAIN, 15));
		welcomeLabel.setBounds(73, 10, 283, 22);
		
		
		
		
		
		JLabel selectLabel = new JLabel("Please Select a Faculty Name:");
		selectLabel.setBounds(123, 38, 185, 14);
		
		
		JSeparator separator1 = new JSeparator();
		separator1.setBounds(10, 262, 406, 2);
		
		
		frame.getContentPane().add(welcomeLabel);
		frame.getContentPane().add(selectLabel);
		frame.getContentPane().add(teacherBox);
		frame.getContentPane().add(separator1);
		frame.getContentPane().add(scoreButton);
		frame.getContentPane().add(generateButton);
		
		
	}
}

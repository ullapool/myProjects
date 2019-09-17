package main;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.scene.control.Button;

public class Main extends Application {

    Button okButton;
    Button clearButton;
    @Override
    public void start(Stage primaryStage) throws Exception{
        //Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("TomTiT");
        GridPane gp = new GridPane();
        gp.setVgap(8);
        gp.setHgap(10);
        Label label1 = new Label("Username: ");
        GridPane.setConstraints(label1,0,0);
        TextField input1 = new TextField();
        GridPane.setConstraints(input1,1, 0);


        okButton = new Button("ok");
        GridPane.setConstraints(okButton, 2, 10);
        clearButton = new Button("clear");
        GridPane.setConstraints(clearButton, 2, 5);
        gp.getChildren().addAll(label1,input1, okButton, clearButton);
        Scene scene = new Scene(gp, 350, 300);
        primaryStage.setScene(scene);

        primaryStage.show();

    }


    public static void main(String[] args) {

        launch(args);
    }
}

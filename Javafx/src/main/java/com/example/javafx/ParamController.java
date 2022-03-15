package com.example.javafx;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

import java.io.IOException;

public class ParamController {

    @FXML
    private Label paramText;

    @FXML
    protected void onBack() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("hello-view.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) paramText.getScene().getWindow();
        thisStage.setTitle("Rechercher");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Boutton retour appuyé");
    }
    @FXML
    protected void onConnexionAdmin() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("admin.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) paramText.getScene().getWindow();
        thisStage.setTitle("Connexion administrateur");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Boutton admin appuyé");
    }
}

package com.example.javafx;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

import java.io.IOException;

public class RechercheController {

    @FXML
    private Label welcomeText;

    @FXML
    protected void onClickSearch() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("loading.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) welcomeText.getScene().getWindow();
        thisStage.setTitle("Chargement des résultats");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Boutton recherche appuyé");
    }
    @FXML
    protected void onClickParam() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("parametre.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) welcomeText.getScene().getWindow();
        thisStage.setTitle("Paramètres");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Boutton paramètre appuyé");
    }
}
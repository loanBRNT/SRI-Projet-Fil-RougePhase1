package com.example.javafx;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

import java.io.IOException;

public class AdminController {

    @FXML
    private Label connexionAdministrateur;

    @FXML
    protected void onBackParam() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("parametre.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) connexionAdministrateur.getScene().getWindow();
        thisStage.setTitle("Paramètres");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Boutton retour appuyé");
    }

    @FXML
    protected void onConnexion() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("paramAdmin.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) connexionAdministrateur.getScene().getWindow();
        thisStage.setTitle("Panneau de configuration");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Connexion autorisée");
    }
}

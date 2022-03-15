package com.example.javafx;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

import java.io.IOException;

public class ResultatsController {
    @FXML
    private Label bongResultats;

    @FXML
    protected void onRelancerRecherche() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("hello-view.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) bongResultats.getScene().getWindow();
        thisStage.setTitle("Rechercher");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Bouton relancé appuyé");
    }
}

package com.example.javafx;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

import java.io.IOException;

public class LoadingController {


    @FXML
    private Label bongLoading;

    @FXML
    protected void onLoadingAchieve() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("resultats.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) bongLoading.getScene().getWindow();
        thisStage.setTitle("Résultats");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Recherche terminée");
    }
}

package com.example.javafx;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

import java.io.IOException;

public class ParamAdminController {

    @FXML
    private Label panneauAdminText;

    @FXML
    protected void onApplyParamAdmin() throws IOException {
        Parent param = FXMLLoader.load(getClass().getResource("parametre.fxml"));
        Scene scene = new Scene(param);
        Stage thisStage = (Stage) panneauAdminText.getScene().getWindow();
        thisStage.setTitle("Paramètres");
        thisStage.setScene(scene);
        thisStage.show();
        System.out.println("Boutton appliqué appuyé");
    }
}

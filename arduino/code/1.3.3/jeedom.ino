void Send_Jeedom(int Jeedom_id, float value) {
  Serial.print("Send to Jeedom: ID=");
  Serial.print(Jeedom_id);
  Serial.print(", Value=");
  Serial.println(value);
  HTTPClient http;
String  Jeedom_Commande = "http://" + Jeedom_Url + "/core/api/jeeApi.php?apikey=" + jeedom_ApiKey + "&plugin=virtual&type=event&id=" + Jeedom_id + "&value=" + value;
  http.begin(Jeedom_Commande.c_str());
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    String Donnees_HTTP = http.getString();
    Serial.print("Reponse HTTP: ");
    Serial.print(httpResponseCode);
    Serial.println(Donnees_HTTP);
  }
  http.end();
}

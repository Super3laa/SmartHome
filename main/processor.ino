String processor(const String& var) {
  Serial.println(var);
  if (var == "STATE") {
    if (digitalRead(LED_BUILTIN) == HIGH) {
      return "OFF";
    }
    else {
      return "ON";
    }
  }
  return String();
}

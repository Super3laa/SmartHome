void handleRoutes(){
  SoftAPInit();
  startMDNS();
  homePage();
  LED();
  tempHum();
  securityInfo();
  UpdateStatus();
  SystemControl();  
}

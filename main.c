#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>





int main() {
		
	
	int ayKacGun;

	printf("Bu ay kac gun: ");
	
	if(scanf("%d", &ayKacGun) != 1) {
		
		printf("Gecersiz ay degeri girisi! Ay degeri sayi degeri olmalidir!");
		
	} else {
		
		if (ayKacGun == 28 || ayKacGun == 30 || ayKacGun == 31) {
			
			int haftalikTatilSayisi;
			char tatilGunu[50];
			
			printf("Haftalik resmi tatil gunu sayiniz: ");
			
			if (scanf("%d", &haftalikTatilSayisi) != 1) {
				
				printf("Gecersiz haftalik tatil sayisi deger girisi! Haftalik tatil sayisi degeri sayi olmalidir! ");
				
			} else {
				
				if (haftalikTatilSayisi < 0) {
					
					printf("Tatil gunu degeri negatif girilemez!");
					
				} else if (haftalikTatilSayisi > 7) {
					
					printf("Haftalik Tatil gunu sayisi 7'den daha fazla olamaz!");
					
				} else if(haftalikTatilSayisi == 0) {
					
					printf("\n");
					printf("NOT: Tatil gununuz olmamasi sebebiyle maasiniza sadece normal gunler yapilan mesai ucreti eklenecektir.\n\n");
					
					double katNormal;
					
					printf("Normal calisma saati disi calisma icin - 1 saat mesai ucreti normal mesai ucretinin kac kati:  ");
					
					if(scanf("%lf", &katNormal) != 1) {
						
						printf("Gecersiz kat degeri girisi!");
						
					} else {
						
						if (katNormal <= 0) {
							
							printf("Kat degeri negatif ya da 0 olamaz!");
							
						} else {
							
							double katResmi;
							
							printf("Resmi tatil gunu icin - 1 saat mesai ucreti normal mesai ucretinin kac kati:  ");
							
							if(scanf("%lf", &katResmi) != 1) {	
							
								printf("Gecersiz kat degeri girisi!");	
							
							} else {
								
								if (katResmi <= 0) {
							
									printf("Kat degeri negatif ya da 0 olamaz!");
							
								} else {
									
									double NetMaas;
							
									printf("Net Maasiniz; ");
							
									if (scanf("%lf", &NetMaas) != 1) {
								
										printf("Gecersiz maas girisi!");
								
									} else {
										
										if(NetMaas < 0) {
											
											printf("Maas degeri negatif olamaz!");
											
										} else if (NetMaas == 0) {
											
											printf("Maas degeri 0 olamaz!");
											
										} else {
											
											double gunlukMaasDegeri = NetMaas / 30;
											double saatlikMaasDegeri = NetMaas / 225;
										
											double MesaiSaatiNormal, MesaiSaatiResmi;
										
											printf("Normal gun yapilan mesai saati sayisi: ");
											
											if(scanf("%lf", &MesaiSaatiNormal) != 1) {
												
												printf("Mesai saati degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
												
											} else {
												
												if(MesaiSaatiNormal < 0) {
													
													printf("Mesai saati negatif olamaz!");
													
												} else if (MesaiSaatiNormal >= 0 && MesaiSaatiNormal <= 560) {
													
													printf("Resmi tatil gunu yapilan mesai saati sayisi: ");
													
													if(scanf("%lf", &MesaiSaatiResmi) != 1) {
														
														printf("Mesai saati degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
														
													} else {
														
														if (MesaiSaatiResmi < 0) {
															
															printf("Mesai saati negatif olamaz!");
															
														} else if (MesaiSaatiResmi >= 0 && MesaiSaatiResmi <= 850) {
															
															double normalGunMesaiKazanc = katNormal * MesaiSaatiNormal * saatlikMaasDegeri;	
															double resmiGunMesaiKazanc = katResmi * MesaiSaatiResmi * saatlikMaasDegeri;
														
															int eksikGelinenGun;
															double eksikGelinenSaat;
															
															printf("Ise gelinmeyen gun sayisi: ");
															
															if (scanf("%d", &eksikGelinenGun) != 1) {
																
																printf("Eksik gelinen gun degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																
															} else {
																
																if(eksikGelinenGun < 0) {
																	
																	printf("Eksik gelinen gun degeri negatif olamaz!");
																	
																} else if ((eksikGelinenGun >= 0 && eksikGelinenGun <= ayKacGun)) {
																	
																	printf("Ise gelinmeyen saat sayisi: ");
																	
																	if(scanf("%lf", &eksikGelinenSaat) != 1) {
																		
																		printf("Eksik gelinen saat degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																		
																	} else {
																		
																		if (eksikGelinenSaat < 0) {
																			
																			printf("Eksik gelinen saat degeri negatif olamaz!");
																			
																		} else if (eksikGelinenSaat >= 0 && eksikGelinenSaat <= ayKacGun * 24) {
																			
																			double MaastanDusulecekGunParasi = eksikGelinenGun * gunlukMaasDegeri;
																			double MaastanDusulecekSaatParasi = eksikGelinenSaat * saatlikMaasDegeri;
																	
																			double alinacakToplamMaas = 0;
																	
																			alinacakToplamMaas = (gunlukMaasDegeri * ayKacGun) + normalGunMesaiKazanc + resmiGunMesaiKazanc  - MaastanDusulecekGunParasi - MaastanDusulecekSaatParasi;
																	
																			printf("Alacaginiz Maas: %lf", alinacakToplamMaas);
																			
																		} else {
																			
																			printf("Bu ay %d saat bulunmaktadir :) ", ayKacGun * 24);
																			
																		}
																	}
																} else {
																	
																	printf("Bu ay %d gun bulunmaktadir :) ", ayKacGun);
																	
																}
															}
														} else {
															
															printf("Matematiksel olarak 1 aylýk mesai degeri mantikli degil!");
															
														}
													}
												} else {
													
													printf("Matematiksel olarak 1 aylýk mesai degeri mantikli degil!");
													
												}
											}
										}
									}
								}
							}
						}				
					}
				} else if (haftalikTatilSayisi == 1) {
					
					printf("Haftanin tatil gunu: ");
					
					if(scanf(" %s", &tatilGunu) != 1) {
						
						printf("Tatil gunu sadece harflerden olusmalidir!");
						
					} else {
						
						int i = 0;
						
   						while (tatilGunu[i]) {
   							
        					tatilGunu[i] = tolower(tatilGunu[i]);
        					
       						i++;
       						
   						}
   						
   						double katNormal;
   						
   						printf("Normal calisma saati disi calisma icin - 1 saat mesai ucreti normal mesai ucretinin kac kati:  ");
   						
   						if(scanf("%lf", &katNormal) != 1) {
						
							printf("Gecersiz kat degeri girisi!");
						
						} else {
						
							if(katNormal <= 0) {
							
								printf("Kat degeri negatif ya da 0 olamaz!");
							
							} else {
							
								double katResmi;
							
								printf("Resmi tatil gunu icin - 1 saat mesai ucreti normal mesai ucretinin kac kati:  ");
							
								if(scanf("%lf", &katResmi) != 1) {	
							
									printf("Gecersiz kat degeri girisi!");	
							
								} else {
								
									if (katResmi <= 0) {
							
										printf("Kat degeri negatif ya da 0 olamaz!");
							
									} else {
								
										double katTatil;
							
										printf("%s gunu icin - 1 saat mesai ucreti normal mesai ucretinin kac kati:  ", tatilGunu);
							
										if(scanf("%lf", &katTatil) != 1) {	
							
											printf("Gecersiz kat degeri girisi!");	
							
										} else {
								
											if (katTatil <= 0) {
							
												printf("Kat degeri negatif ya da 0 olamaz!");
							
											} else {
									
												double NetMaas;
							
												printf("Net Maasiniz; ");
							
												if (scanf("%lf", &NetMaas) != 1) {
											
													printf("Gecersiz maas girisi!");
								
												} else {
													
													if (NetMaas < 0) {
														
														printf("Maas degeri negatif olamaz!");
														
													} else if (NetMaas == 0) {
														
														printf("Maas degeri 0 olamaz!");
														
													} else {
														
														double gunlukMaasDegeri = NetMaas / 30;
														double saatlikMaasDegeri = NetMaas / 225;
										
														double MesaiSaatiNormal, MesaiSaatiResmi, MesaiSaatiTatil;
													
														printf("Normal gun yapilan mesai saati sayisi: ");
													
														if (scanf("%lf", &MesaiSaatiNormal) != 1) {
														
															printf("Mesai saati degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
														
														} else {
														
															if(MesaiSaatiNormal < 0) {
															
																printf("Mesai saati negatif olamaz!");
															
															} else if (MesaiSaatiNormal >= 0 && MesaiSaatiNormal <= 480) {
															
																printf("Resmi tatil gunu yapilan mesai saati sayisi: ");
															
																if (scanf("%lf", &MesaiSaatiResmi) != 1 ) {
																
																	printf("Mesai saati degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																
																} else {
																
																	if (MesaiSaatiResmi < 0) {
																	
																		printf("Mesai saati negatif olamaz!");
																	
																	} else if (MesaiSaatiResmi >= 0 && MesaiSaatiResmi <= 850) {
																
																		printf("%s tatil gunu yapilan mesai saati sayisi: ", tatilGunu);
																	
																		if(scanf("%lf", &MesaiSaatiTatil) != 1) {
																		
																			printf("Mesai saati degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																		
																		} else {
																		
																			if(MesaiSaatiTatil < 0) {
																			
																				printf("Mesai saati negatif olamaz!");
																			
																			} else if (MesaiSaatiTatil >= 0 && MesaiSaatiTatil <= 130) {
																			
																				double normalGunMesaiKazanc = katNormal * MesaiSaatiNormal * saatlikMaasDegeri;	
																				double resmiGunMesaiKazanc = katResmi * MesaiSaatiResmi * saatlikMaasDegeri;
																				double tatilGunMesaiKazanc = katTatil * MesaiSaatiTatil * saatlikMaasDegeri;
																			
																				int eksikGelinenGun;
																				double eksikGelinenSaat;
																
																				printf("Ise gelinmeyen gun sayisi: ");
																			
																				if(scanf("%d", &eksikGelinenGun) != 1) {
																				
																					printf("Eksik gelinen gun degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																				
																				} else {
																				
																					if(eksikGelinenGun < 0) {
																					
																						printf("Eksik gelinen gun degeri negatif olamaz!");
																					
																					} else if (eksikGelinenGun >= 0 && eksikGelinenGun <= ayKacGun) {
																					
																						printf("Ise gelinmeyen saat sayisi: ");
																					
																						if(scanf("%lf", &eksikGelinenSaat) != 1) {
																						
																							printf("Eksik gelinen saat degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																						
																						} else {
																						
																							if (eksikGelinenSaat < 0) {
																							
																								printf("Eksik gelinen saat degeri negatif olamaz!");
																							
																							} else if (eksikGelinenSaat >= 0 && eksikGelinenSaat <= ayKacGun * 24) {
																							
																								double MaastanDusulecekGunParasi = eksikGelinenGun * gunlukMaasDegeri;
																								double MaastanDusulecekSaatParasi = eksikGelinenSaat * saatlikMaasDegeri;
																						
																								double alinacakToplamMaas = 0;
																			
																								alinacakToplamMaas = (gunlukMaasDegeri * ayKacGun) + normalGunMesaiKazanc + resmiGunMesaiKazanc + tatilGunMesaiKazanc - MaastanDusulecekGunParasi - MaastanDusulecekSaatParasi;
																			
																								printf("Alacaginiz Maas: %lf", alinacakToplamMaas);
																					
																							} else {
																							
																								printf("Bu ay %d gun bulunmaktadir :) ", ayKacGun * 24);
																							
																							}
																						}
																					} else {
																					
																						printf("Bu ay %d gun bulunmaktadir :) ", ayKacGun);
																					
																					}
																				}
																			} else {
																			
																				printf("Matematiksel olarak 1 aylýk mesai degeri mantikli degil!");
																			
																			}
																		}
																	} else {
																	
																		printf("Matematiksel olarak 1 aylýk mesai degeri mantikli degil!");
																	
																	}
																}
															} else {
															
																printf("Matematiksel olarak 1 aylýk mesai degeri mantikli degil!");
															
															}
														}
													}
												}
   											}
										}
									} 
								}	
							}
						}
					}
				} else if (haftalikTatilSayisi > 1) {
					
					char diziTatilGunu[haftalikTatilSayisi][50];
					int k, i, harfMi;
					
					for(k=0; k<haftalikTatilSayisi; k++) {
						
						printf("Haftanin %d. tatil gunu: ", k+1);
						scanf("%s", diziTatilGunu[k]);
						
						for(i=0; i<strlen(diziTatilGunu[k]); i++) {
							
							if(!isalpha(diziTatilGunu[k][i])) { 
								
								harfMi = 0;
								printf("Tatil gunu sadece harflerden olusmalidir!\n");
								k--;
								break;
								
							} else {
								 
								int m;
								
								for(m=0; m<strlen(diziTatilGunu[k]); m++) {	
									
									diziTatilGunu[k][m] = tolower(diziTatilGunu[k][m]);
										
								}
							} 					
						}
					} 
					
					double katNormal;
   						
   						printf("Normal calisma saati disi calisma icin - 1 saat mesai ucreti normal mesai ucretinin kac kati:  ");
					
					if(scanf("%lf", &katNormal) != 1) {
						
							printf("Gecersiz kat degeri girisi!");
						
					} else {
						
						if(katNormal <= 0) {
							
							printf("Kat degeri negatif ya da 0 olamaz!");
							
						} else if (katNormal <= 20) {
							
							double katResmi;
							
							printf("Resmi tatil gunu icin - 1 saat mesai ucreti normal mesai ucretinin kac kati:  ");
							
							if(scanf("%lf", &katResmi) != 1) {	
							
								printf("Gecersiz kat degeri girisi!");	
							
							} else {
								
								if (katResmi <= 0) {
							
									printf("Kat degeri negatif ya da 0 olamaz!");
							
								} else if (katResmi <= 20) {
										
									int a, b;
									double katTatilDizi[haftalikTatilSayisi];
									int kontrol;
										
									for(a=0; a<haftalikTatilSayisi; a++){
										
										printf("%s gunu icin - 1 saat mesai ucreti normal mesai ucretinin kac kati: ", diziTatilGunu[a]);
											
										kontrol = scanf("%lf", &katTatilDizi[a]);	
											
										if(kontrol != 1 || katTatilDizi[a] <= 0 || katTatilDizi[a] > 20) {
												
											printf("Gecersiz kat degeri girisi!\n");
											break;
										} 
									}
									
									if (kontrol == 1 || katTatilDizi[a] <= 20) {
										
										double NetMaas;
							
										printf("Net Maasiniz; ");
							
										if (scanf("%lf", &NetMaas) != 1) {
											
											printf("Gecersiz maas girisi!");
								
										} else {
													
											if (NetMaas < 0) {
														
												printf("Maas degeri negatif olamaz!");
														
											} else if (NetMaas == 0) {
														
												printf("Maas degeri 0 olamaz!");
														
											} else {
														
												double gunlukMaasDegeri = NetMaas / 30;
												double saatlikMaasDegeri = NetMaas / 225;
	
												double MesaiSaatiNormal, MesaiSaatiResmi;
														
												printf("Normal gun yapilan mesai saati sayisi: ");
													
												if (scanf("%lf", &MesaiSaatiNormal) != 1) {
														
													printf("Mesai saati degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
														
												} else {
														
													if(MesaiSaatiNormal < 0) {
															
														printf("Mesai saati negatif olamaz!");
															
													} else if (MesaiSaatiNormal >= 0 && MesaiSaatiNormal <= 480) {
															
														printf("Resmi tatil gunu yapilan mesai saati sayisi: ");
															
														if (scanf("%lf", &MesaiSaatiResmi) != 1 ) {
																
															printf("Mesai saati degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																
														} else {
																
															if (MesaiSaatiResmi < 0) {
																	
																printf("Mesai saati negatif olamaz!");
																	
															} else if (MesaiSaatiResmi >= 0 && MesaiSaatiResmi <= 850) {
																		
																int y;
																double MesaiSaatiTatil[haftalikTatilSayisi];
																int kontrol2;
																		
																for (y=0; y<haftalikTatilSayisi; y++) {
																			
																	printf("%s tatil gunu yapilan mesai saati sayisi: ", diziTatilGunu[y]);
																	kontrol2 = scanf("%lf", &MesaiSaatiTatil[y]);	
											
																	if(kontrol2 != 1 || MesaiSaatiTatil[y] < 0 || MesaiSaatiTatil[y] > 24 * haftalikTatilSayisi) {
												
																		printf("Gecersiz mesai degeri girisi!\n");
																		break;
																				
																	} 
																}
																		
																if(kontrol2 == 1) {
																			
																	int z;
																	double tatilGunMesaiKazanc = 0;
																	double toplam ;
																	double normalGunMesaiKazanc = katNormal * MesaiSaatiNormal * saatlikMaasDegeri;	
																	double resmiGunMesaiKazanc = katResmi * MesaiSaatiResmi * saatlikMaasDegeri;
																			
																	for(z=0; z<haftalikTatilSayisi; z++) {
																				
																		toplam = katTatilDizi[z] * MesaiSaatiTatil[z];
																		tatilGunMesaiKazanc = tatilGunMesaiKazanc + toplam;	
																	}	
																	
																	tatilGunMesaiKazanc = tatilGunMesaiKazanc * saatlikMaasDegeri;
																	printf("%lf", tatilGunMesaiKazanc);
																	int eksikGelinenGun;
																	double eksikGelinenSaat;
															
																	printf("Ise gelinmeyen gun sayisi: ");
																			
																	if(scanf("%d", &eksikGelinenGun) != 1) {
																				
																		printf("Eksik gelinen gun degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																				
																	} else {
																				
																		if(eksikGelinenGun < 0) {
																					
																			printf("Eksik gelinen gun degeri negatif olamaz!");
																					
																		} else if (eksikGelinenGun >= 0 && eksikGelinenGun <= ayKacGun) {
																					
																			printf("Ise gelinmeyen saat sayisi: ");
																					
																			if(scanf("%lf", &eksikGelinenSaat) != 1) {
																						
																				printf("Eksik gelinen saat degeri yalnýzca sayýsal degerlerden oluþmalýdýr!");
																						
																			} else {
																						
																				if (eksikGelinenSaat < 0) {
																							
																					printf("Eksik gelinen saat degeri negatif olamaz!");
																							
																				} else if (eksikGelinenSaat >= 0 && eksikGelinenSaat <= ayKacGun * 24) {
																							
																					double MaastanDusulecekGunParasi = eksikGelinenGun * gunlukMaasDegeri;
																					double MaastanDusulecekSaatParasi = eksikGelinenSaat * saatlikMaasDegeri;
																						
																					double alinacakToplamMaas;
																								
																					alinacakToplamMaas = (gunlukMaasDegeri * ayKacGun) + normalGunMesaiKazanc + resmiGunMesaiKazanc + tatilGunMesaiKazanc - MaastanDusulecekGunParasi - MaastanDusulecekSaatParasi;
																					printf("Alacaginiz Maas: %lf", alinacakToplamMaas);
																								
																				} 
																			}
																		} 
																	}
																} 
															}
														} 
													}
												} 
											}		
										}
									}
								}
							}
						}
					}
				}
			}	
		} else {
			
			printf("Gecersiz ay degeri girisi!");
			
		}
	}
	

	
	return 0;
	
	
}
 

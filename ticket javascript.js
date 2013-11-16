
			
				
				var tokenSend = "";

				function submitForm(frmId, operation, type){
					
					if("308512" != $("#card").val().substring(0,6)){
						valido = validarConsultCard(frmId);
						if (valido) {
							if(operation == "balance"){
								loaderConsultCard(true,"223px", "180px", "268px");
							} else if (operation == "release"){
								load(true,"700px");
							}
							$.ajax({
							  dataType: type,
							  url: '/portal-web/consult-card/'+operation+'/'+type+'?'+$('#'+frmId).serialize(),
							  success: function(data){
								  if(operation == "balance"){
									  loaderConsultCard(false,"", "", ""); 
								  } else if (operation == "release"){
									  load(false,"700px"); 
								  }
								  if(data.status){
										if(operation == "balance"){
											displayNoneConsult();
											tokenSend = data.token;
											preencherPainelSaldos(data.card.balance.date, data.card.balance.value, data.card.scheduling, data.card.balance.bin);
											_gaq.push(['_trackPageview','/portal/portalcorporativo/usuario/consulte-seu-saldo/popup-consulta-saldo.htm']);
										} else if(operation == "release"){
											preencherHead(data.card.balance.number,data.card.balance.date);
											if(data.card.release != null){
												construirPagConsult("consulteSeuSaldoLancamentos_paginacaoLancamentos", data.card.release, preencherHistory);
											}
											if(data.card.scheduling[0] != null){
												preencherAgendamentoRelease(data.card.scheduling);
											}
											_gaq.push(['_trackPageview','/portal/portalcorporativo/usuario/consulte-seu-saldo/popup-consulta-saldo.htm']);
										}
									} else {
										if(operation == "balance"){
											displayNoneConsult();
											notCard(data.messageError);
										} else if(operation == "release"){
											window.location = "http://"+pegaDominio()+"/portal/portalcorporativo";
										}
									}
								},
								error: function(msg) {
									alert(msg.statusText);
						       }
							});
						}
					} else {
						displayNoneConsult();
						notCard("N\u00E3o existe consulta de saldo para esse produto.");
					}
				}
				
				
				function preencherPainelSaldos(data, saldo, agendamentos, prodCard) {
					
					displayNoneConsult();
					
					$("#consulteSeuSaldo_divResultadoAgendamento").attr("style","display:block; margin-top: 10px;");
					$("#consulteSeuSaldo_divBotaoNovaConsulta").attr("style","display:block;");
					
					preencherSaldo(saldo, data);
					
					jQuery("#consulteSeuSaldo_spanNumeroCartao").empty().append(obterNumeroCartaoFormatado($("#card").val()));
					jQuery("#consulteSeuSaldo_spanDataAtual").empty().append(data);
					
					if(prodCard == "TC"){
						jQuery("#consulteSeuSaldo_aHistoricoAgendamentos").removeClass("ativar").addClass("desativar").hide();
						jQuery("#consulteSeuSaldo_aMsgTc").removeClass("desativar").addClass("ativar").show();
					} else {
						jQuery("#consulteSeuSaldo_aMsgTc").removeClass("ativar").addClass("desativar").hide();
						jQuery("#consulteSeuSaldo_aHistoricoAgendamentos").removeClass("desativar").addClass("ativar").show();
						jQuery("#consulteSeuSaldo_aHistoricoAgendamentos").attr("title", "Hist\u00F3rico de Lan\u00E7amentos e Agendamentos Atualizados em " + data);
					}
					
					if (agendamentos[0] != null) {
						preencherAgendamento(agendamentos);
						jQuery(".portal_resultadoAgendamentos").show();
					} else {
						jQuery(".portal_resultadoAgendamentos").hide();
					}
				
				}
				
				function preencherSaldo(saldo, data) {
					jQuery("#consulteSeuSaldo_tdDataSaldo").empty().append(data);
					jQuery("#consulteSeuSaldo_tdValorSaldo").empty().append(saldo);
				}
				
				function preencherAgendamento(agendamentos) {
					var tbody = jQuery("#consulteSeuSaldo_tbodyAgendamentos");
					tbody.empty();
					tbody.append("<tr><td style='font-size: 10px'>Agendamentos:</td><td style='font-size: 10px'>" + agendamentos[0].date + "</td><td style='font-size: 10px'>" + agendamentos[0].value + "</td></tr>");
				}
				
				function displayNoneConsult(){
					$("#consulteSeuSaldo_divConsultarSaldo").attr("style","display:none;");
					$("#consulteSeuSaldo_divCartaoInexistente").attr("style","display:none;");
					$("#consulteSeuSaldo_divResultadoAgendamento").attr("style","display:none;");
					$("#consulteSeuSaldo_divBotaoNovaConsulta").attr("style","display:none;");
				}
				
				function prepararNovaConsultaSaldo() {
					displayNoneConsult();
					$("#consulteSeuSaldo_divConsultarSaldo").attr("style","display:block;");
					document.forms['frmConsulteSeuSaldo'].reset();
					$("#card").focus();
				}
				
				function validarConsultCard(frmId) {
					return validateForm(frmId, {
						rules: {
							card: {required: true}
						},
						messages: {
							card: {required: requiredMessage}
						}
					});
				}	
				
				
				function loaderConsultCard(load, width, height, left){
					if(load){
						$("#pLoadCard").attr("style", "z-index:100000; background: none repeat scroll 0 0 #FFFFFF; height:"+height+"; %right: 200px; *filter: alpha(opacity=60); opacity: 0.6; position: absolute; width:"+width+";").append("<img id='imgLoadCard' style=' margin-left:85px; margin-top:65px; position: fixed;' src='/portal/library/images/preloader.gif'/>");
					} else {
						$("#pLoadCard").attr("style", "");
						$("#imgLoadCard").remove();
					}
				}	
				
				function notCard(msn){
					var bufferError = new StringBuffer();
					
					$("#consulteSeuSaldo_divCartaoInexistente").attr("style","display:block; margin-top: 40px;");
					$("#consulteSeuSaldo_divBotaoNovaConsulta").attr("style","display:block; margin-top: 20px;");
					
					$("#msnErroCard").remove();
					bufferError.append("<div id='msnErroCard'>");
						bufferError.append(msn);
					bufferError.append("</div>");	
					$("#consulteSeuSaldo_divCartaoInexistente").html(bufferError.toString());
					
				}
				
				
				function irParaHistoricoSaldo() {
					cardNumber = $("#card").val();
					location.href= "http://"+ pegaDominio() +"/portal/portalcorporativo/usuario/consulte-seu-saldo/consulte-seu-saldo.htm?card=" + cardNumber + "&token=" + tokenSend;
				}
				
				
				//Release
				
				function preencherHead (cardNumber, consultDate) {
					
					var bufferHead = new StringBuffer();
					$("#listHead").remove();
					
					bufferHead.append("<p><strong>N&#186; do Cart&#227;o:</strong>&#160;" + cardNumber + "</p>");
					bufferHead.append("<p><strong>Hist&#243;rico de Lan&#231;amentos e Agendamentos:</strong>&#160;(atualizado em&#160;"+ consultDate +")</p>");
					bufferHead.append("<br clear='all' />");
					
					$("#resultHead").html(bufferHead.toString());
				}
				
				function preencherHistory(releases){
				
					var bufferHistory = new StringBuffer();
					$("#listHistory").remove();
				
					bufferHistory.append("<br clear='all' />");
					bufferHistory.append("<div id='divListAbrangencia'>");
						bufferHistory.append("<table cellspacing='0' cellpadding='0' class='tabelaCo2'>");
							bufferHistory.append("<tbody id='consulteSeuSaldoLancamentos_tbodyLancamentos'>");
								bufferHistory.append("<tr class='top_blue'>");
									bufferHistory.append("<td width='70%'>Lan&#231;amentos</td>");
									bufferHistory.append("<td width='15%''>Data</td>");
									bufferHistory.append("<td width='15%'>Valor</td>");
								bufferHistory.append("</tr>");
							for(var i=0; i<releases.length; i++){
								var classTds = ((i % 2) == 0) ? "" : "azul";
								bufferHistory.append("<tr class='"+classTds+"'>");
									bufferHistory.append("<td>"+ releases[i].description +"</td>");
									bufferHistory.append("<td>"+ releases[i].date +"</td>");
									bufferHistory.append("<td>"+ releases[i].value +"</td>");
								bufferHistory.append("</tr>");
							}
							bufferHistory.append("</tbody>");
						bufferHistory.append("</table>");
					bufferHistory.append("</div>");
					
					$("#resultHistory").html(bufferHistory.toString());
				}
				
				
				
				function preencherAgendamentoRelease(scheduling){
					
					var bufferAgendamento = new StringBuffer();
					$("#listAgendamento").remove();
				
					bufferAgendamento.append("<br clear='all' />");
					bufferAgendamento.append("<div id='divListAbrangencia'>");
						bufferAgendamento.append("<table cellspacing='0' cellpadding='0' class='tabelaCo2'>");
							bufferAgendamento.append("<tbody id='consulteSeuSaldoLancamentos_tbodyAgendamentos'>");
								bufferAgendamento.append("<tr class='top_blue'>");
									bufferAgendamento.append("<td width='70%'>Lan&#231;amentos</td>");
									bufferAgendamento.append("<td width='15%''>Data</td>");
									bufferAgendamento.append("<td width='15%'>Valor</td>");
								bufferAgendamento.append("</tr>");
								for(var i=0; i<scheduling.length; i++){
									var classTdss = ((i % 2) == 0) ? "" : "azul";
									bufferAgendamento.append("<tr class='"+classTdss+"'>");
										bufferAgendamento.append("<td>"+ scheduling[i].description +"</td>");
										bufferAgendamento.append("<td>"+ scheduling[i].date +"</td>");
										bufferAgendamento.append("<td>"+ scheduling[i].value +"</td>");
									bufferAgendamento.append("</tr>");
								}
							bufferAgendamento.append("</tbody>");
						bufferAgendamento.append("</table>");
					bufferAgendamento.append("</div>");
					
					$("#resultAgendamento").html(bufferAgendamento.toString());
				}
				
				
				//Inicio da Paginacao
				
				var portalConsultCard_paginas = [],
					portalConsultCard_registrosPorPagina = 10;
				
				function construirPagConsult(idElemento, lista, funcaoPreenchimento) {
					var elemento = portalConsultCard_paginas[idElemento],
						numPaginas = contItens = 1,
						itensPaginas = [];
					
					if (lista.length > portalConsultCard_registrosPorPagina) {
						numPaginas = Math.ceil(lista.length / portalConsultCard_registrosPorPagina);
					}
					
					if ((elemento == undefined) || (elemento == null)) {
						elemento = $("#" + idElemento);
						portalConsultCard_paginas[idElemento] = elemento;
					}
					
					elemento.empty().append($("<p />").addClass("text"));
					
					elemento.addClass("paginacao");
					elemento.idElemento = idElemento;
					elemento.numPaginas = numPaginas;
					elemento.lista = lista;
					elemento.funcao = funcaoPreenchimento;
					elemento.itens = itensPaginas;
					
					if (lista.length > 0) {
					
						for (var i = 1; i <= numPaginas; i++) {
							var limite = i * portalConsultCard_registrosPorPagina;
							
							itensPaginas[i - 1] = [];
							
							for (var j = contItens; (j <= limite) && (j <= lista.length); j++, contItens++) {
								itensPaginas[i - 1].push(lista[j - 1]);
							}
							
						}
						
						paginarConsultCard(idElemento, 1);
					}
					
				}
				
				function paginarConsultCard(idElemento, pagina) {
					var elemento = portalConsultCard_paginas[idElemento];
					
					construirLinksPagConsultCard(elemento, pagina);
					
					elemento.find("p.text").empty().append("P&aacute;gina " + pagina + " de " + elemento.numPaginas);
					jQuery("#" + idElemento + "_pagina" + pagina).addClass("ativo");
					
					elemento.funcao(elemento.itens[pagina - 1]);
				}
				
				
				function construirLinksPagConsultCard(elemento, pagina) {
					var linksCriados = [], 
						total = elemento.numPaginas,
						limiteMuitasPaginas = 6,
						criarLinkAnterior = criarLinkPrimeiro = criarLinkUltimo = muitasPaginas = false;
					
					elemento.find("a").remove();
					
					if (elemento.numPaginas > limiteMuitasPaginas) {
						
						if (pagina > 1) {
							criarLinkAnterior = true;
							
							if (pagina > 5) {
								criarLinkPrimeiro = true;
							}
							
						}
						
						if (pagina < (total - 4)) {
							criarLinkUltimo = true;
						}
						
						muitasPaginas = true;
					}
					
					if ((pagina < 4) || !muitasPaginas) {
					
						for (var i = 2; (i <= limiteMuitasPaginas) && (i <= elemento.numPaginas); i++) {
							linksCriados.push(i);
						}
						
					} else if (pagina < (total - 3)) {
						linksCriados = [(pagina - 2), (pagina - 1), pagina, (pagina + 1), (pagina + 2)];
					} else {
						linksCriados = [(total - 4), (total - 3), (total - 2), (total - 1)];
					}
					
					if (criarLinkPrimeiro) {
						elemento.append(
								jQuery("<a />")
								.append("<<")
								.attr({
									href: "javascript:paginarConsultCard('" + elemento.idElemento + "', 1);",
									id: elemento.idElemento + "_primeiro"
								})
								.css("margin", "1px")
						);
					}
					
					if (criarLinkAnterior) {
						elemento.append(
								jQuery("<a />")
								.append("<")
								.attr({
									href: "javascript:paginarConsultCard('" + elemento.idElemento + "', " + (pagina- 1) + ");",
									id: elemento.idElemento + "_anterior"
								})
								.css("margin", "1px")
						);
					}
					
					elemento.append(criarLinkPagConsultCard(elemento, 1, pagina, muitasPaginas));
					
					jQuery.each(linksCriados, function(i, itemCriado) {
						elemento.append(criarLinkPagConsultCard(elemento, itemCriado, pagina, muitasPaginas));
					});
						
					if (muitasPaginas) {
						elemento.append(criarLinkPagConsultCard(elemento, elemento.numPaginas, pagina, muitasPaginas));
						
						if (criarLinkUltimo) {
							elemento.append(
									jQuery("<a />")
									.append(">>")
									.attr({
										href: "javascript:paginarConsultCard('" + elemento.idElemento + "', " + elemento.numPaginas + ");",
										id: elemento.idElemento + "_ultimo"
									})
									.css("margin", "1px")
							);
						}
						
					}
					
				}
				
				function criarLinkPagConsultCard(elemento, pagina, paginaAtual, muitasPaginas) {
					var conteudo = pagina, ret = "...";
					
					if ((pagina != paginaAtual) && muitasPaginas) {
					
						if (pagina == 1) {
							conteudo = pagina + ret;
						} else if (pagina == elemento.numPaginas) {
							conteudo = ret + pagina;
						}
					
					}
					
					return jQuery("<a />")
						.append(conteudo)
						.attr({
							href: "javascript:paginarConsultCard('" + elemento.idElemento + "', " + pagina + ");",
							id: elemento.idElemento + "_pagina" + pagina
						})
						.css("margin", "1px");
				}
				
				// Fim da Paginacao
				
				
				
				
<!-- 				$(document).ready(function(){ -->
<!-- 					$("#card").mask("9999999999999999"); -->
<!-- 				}); -->
			
		
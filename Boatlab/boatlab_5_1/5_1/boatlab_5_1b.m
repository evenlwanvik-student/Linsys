clf();

T1 = compass_deg1.time;
psi1 = compass_deg1.signals.values;
T2 = compass_deg2.time
psi2 = compass_deg2.signals.values

% find min and max amplitude of oscillations
window1 = 5000:10000;
A1_min = min(psi1(window));
A1_max = max(psi1(window));
A1 = (A1_max-A1_min)/2
window2 = 5000:10000;
A2_min = min(psi2(window2));
A2_max = max(psi2(window2));
A2 = (A2_max-A2_min)/2

subplot(2,1,1)
plot(T1, psi1)
maxline1 = refline([0 A1_max]);
maxline1.Color = 'r';   
minline1 = refline([0 A1_min]);
minline1.Color = 'r'; 

subplot(2,1,2)
plot(T2, psi2)
maxline2 = refline([0 A2_max]);
maxline2.Color = 'r';   
minline2 = refline([0 A2_min]);
minline2.Color = 'r'; 



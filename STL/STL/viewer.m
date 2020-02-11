clear;
clf;

data_unordered_set_v2;
data_unordered_map_v2;
figure(1)
[m,n]=size(x5);
for i = 2:n
    plot(x5(:,1), x5(:,i));
    hold on
end

title('temps d execution');
legend('temps d execution ajout','temps d execution lecture debut','temps d execution lecture fin','temps d execution lecture aleatoire');

figure(2)
[m,n]=size(x10);
for i = 2:n
    semilog(x10(:,1), x10(:,i));
    hold on
end

title('temps d execution');
legend('temps d execution ajout','temps d execution lecture debut','temps d execution lecture fin','temps d execution lecture aleatoire');

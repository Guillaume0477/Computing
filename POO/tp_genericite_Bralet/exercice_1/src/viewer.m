clear;
clf;

data;
plot(curve(1,:),curve(2,:),'r');
hold on
plot(polygon(1,:),polygon(2,:));
plot(polygon(1,:),polygon(2,:),'r.');
axis equal

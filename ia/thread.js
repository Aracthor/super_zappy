var obj = { run: function() { print("hi"); } };
obj.run();

var runnable = new java.lang.Runnable(obj);
var thread = new java.lang.Thread(runnable);
thread.start();

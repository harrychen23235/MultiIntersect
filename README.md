UI程序在myUI(exe inside)压缩包内，点击myUI.exe运行
load from file:输入在exe同级目录下的txt文件名，文件内容必须按照格式要求
如:1 L 1 1 0 0,点击确认后导入所有图形
directly input:输入图形，如输入L 0 0 1 1,点击确认后导入图形
show point number:弹出窗口，数字就是对应的节点个数
clear:清空所有图形
delete:输入之前添加的图形,如L 0 0 1 1，并点击确认键，就能将之前添加的图形删除
draw:直接弹出绘制图形的窗口
quit:退出UI程序
注:本UI不支持错误处理，因此禁止输入错误数据，如2 L 0 0 1 1 L 0 0 -1 -1等
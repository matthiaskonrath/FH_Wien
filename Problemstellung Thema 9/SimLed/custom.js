$(document).ready(function() {

	var hexdata = [];
	$.ajax({
	url : "input.txt",
	dataType: "text",
	success : function (data) {
		var lines = data.split('\n');
		for( var k=0; k < lines.length; k++ ) {
			if (lines[k].charAt(8) == '0') {
				hexdata.push(lines[k]);
			}
    	}
    	$("#contentArea").html(lines.join("<br/>"));
		//alert('Load was performed.' + hexdata.length);	
	},
	error : function (data) {
		alert('File input.txt not found!');
	}
	});
	
	$(document).everyTime(200, function(i) {
		var line = hexdata[i % hexdata.length];
		$("#contentArea").html(line);
		for (var k = 0; k < 8; k++) {
			var color = "#"+line.charAt(9+k*2)+"0"+line.charAt(10+k*2)+"000";
			$("#led"+k).animate({ backgroundColor: color }, 50);
		}
	});
});
var phone = document.getElementById("Q3").value;
function get()
{
    var phoneno=document.getElementById("Q3").value;
    var a=phoneno.split(" ");
    var areacode = a[1];
    var phon = a[2]+a[3];
    document.getElementById("area-code").value = areacode;
    document.getElementById("phone-no").value = phon;
}
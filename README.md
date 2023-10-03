# PIATRON-Automated-Food-Counter-Mass-Scale

On July 7th, 2023, we started our SIWES 1 program, my group was assigned to build a food monitoring system for the school cafeteria. Usually, when students or staff come to the cafeteria they might get there and see that their food is not available, our task was to help students, staff and other personnel in the school know the amount of each food available for sale at any given moment. After speaking with the school cafeteria staff and our assigned mentors we came up with a solution. 

- First, the amount of food available will have to be uploaded to a database. We achieved this via two methods.

One: building a mass scale to measure the mass of food produced and estimating the number of portions of food being weighed, which is then uploaded to our database. For our database, we decided to use Firebase Realtime Database.

Two: manually inputting the number of portions via a web page

- Secondly, a device is provided to the food vendors, allowing them to deduct the quantity of food as it is sold using the provided interface. This interface utilizes a tap-and-go system, designed to minimize the time spent on deducting sold food items. As deductions are made, the database is automatically updated.

###Technologies used/ Topics covered

- Arduino framework
- Arduino C/C++
- Bluetooth classic via HC-05 Bluetooth module
- Soldering
- Wheatstone bridge
- Stress and Strain principles
- [Floor functions](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)
- [Kodular](https://kodular.io) Low-code development platform
- HTML,CSS,JavaScript
- Firebase

### Materials used
- - Arduino Nano
- -Perspex for enclosure
- -Bolts and nuts
- -L shaped rivets
- - 20kg load cell
- -HX711 24bit ADC amplifier 
- -some wires
- -Jumper cables
- -HC-05 Bluetooth module
- -Female headers
- -Male headers
- -Micro USB breakout board


## The load cell
 The load cell is made of an aluminium bar and 4 strain gauges. A holder is perforated on the aluminium bar so that when force is applied to the rod, most of the stress will be around the perforated area. At the loci where the rod is perforated the 4 strain gauges are placed. This is the ensure that the strain gauge gets the most of the strain applied on the rod. 

When the strain gauges detect any strain, their resistance change, so in order to change their changes in resistance to change in voltage, the four strain gauges are connected in a Wheatstone bridge style

![Wheastone bridge](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/e3uimdsyxwna6q2qkcqb.png)
(Electronoobs, 2020)

However, the voltage change is very small, so we use the HX711 24-bit ADC amplifier to amplify the voltage, which is then fed to the MCU to perform the required calculation to get the weight of an object

## The Mass scale

![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/cik39ld7dzxutuqgvsz2.png)

The mass scale, as the name implies, is designed to measure the mass of food placed on it. To accomplish this, we utilized a 20kg load cell in conjunction with the HX711 24-bit ADC amplifier for precise mass measurement. The measured mass is then transmitted to the mobile app via Bluetooth, employing the HC-05 Bluetooth module. Below is the schematic diagram illustrating the circuit.

![Schematic diagram of mass scale](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/xdto8oo5o29n9ijqbijd.png)


![The circuit](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/on645ovocoxjl435a7z2.png)

To access the design file use this [link](https://a360.co/46bFO4h).


## The mobile app

The mobile app gets the mass of the food via Bluetooth from the mass scale, estimates the number of portions and posts it in the database.

When a user first launches the app, the user will be greeted with the login page

![Login page](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/pbn3k93pzp0tqyceupn8.png)

After the login is successful, the user will then enter the main app page.

![app page](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/tns7ioww4m8o4oz2j1op.jpg)

To connect to the mass scale, the user will have to click on the Bluetooth Icon to activate a list picker with a list of all paired Bluetooth devices. _Note: if you have not paired with the mass scale beforehand, pair with it in your mobile phone Bluetooth settings, as it can't be done from the app_.


![list of paired bluetooth devices](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/lgigy5b4b19gjqul2ffr.jpg)


select the mass scale, its name on the list is H-C-2010-06-01 and wait for it connect. When connected, the "not connected" text will change to "CONNECTED"


![connected](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/azqon0n9xpx71eunhqsc.jpg)

Now that the device is connected when a load is placed upon it you should see the mass in gram on the mobile app.

(image of app showing mass)

To upload food quantity using the weight sensor you have to select the location the food is going to 


![select location](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/5ik50bv4ixz9pxc6f1wa.jpg)

and then you select the food you are weighing.

![select food](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/4kd3ka5dri4rhmm44jrv.jpg)

Then you click the estimate portion button to estimate the amount of food portions in what is being weighed this is done using the mass per portion for the particular food being weighed. Sometimes the results for the calculation return decimals, so a floor function is used to convert it to the greatest integer less than the decimal number obtained. So if the estimated portions was 10.7 portions this means you will see 10 portions on the app and that is what will be sent to the database


![Image when estimate button is pressed](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/xqad0v2v9l3j48l9qil4.png)



The undo button is used to reverse a previous update sent to the database, while the TARE button is used to reset the measurement to zero on weighing scales. The TARE function subtracts the current weight of the container, or any additional load placed on the scale, ensuring that only the net weight of the desired substance is displayed. This is particularly useful when measuring ingredients in cooking or obtaining accurate weight readings in various industrial and laboratory applications. The TARE button essentially "zeroes out" the scale, allowing you to work with precise measurements without needing to account for the weight of the container or other items.

## The Web Application

![Home page](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/62p50gazmihbq9fe6nta.png)
The image above is the home page of the web application where all food is available in the cafeteria, with their quantities at various locations shown. Anyone can access this page. The admin page houses all administrative functions such as:

- Create, edit and delete a food
- Get production and sales report
- Create a food timetable/Menu
- Get sales report

To button to access the admin page is at the top right corner of the page named Admin.

### The Admin dashboard

![Admin dashboard](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/sqlf6d7m12tijnlwwizf.png)

The admin dashboard is the command-and-control centre for the cafeteria staff. For the staff to access this page, they have to log in with the cafeteria email and pin which is sent to them every morning. The admin page boasts many features such as;
1.	The dashboard which when clicked shows; the statistics of the day’s data such as the total food quantity sold, total income, total order received, the most demanded product and the least demanded product. It also contains a create menu button at the top right corner of the page which allows the user to create a menu for the day based on different preset menu groups. A reset button can also be found there, this button resets the quantity of items produced and sold to zero thereby making the quantity available zero. Product data displays the various food items as they are being sold at various locations in the order in which they are entering. 

2. The Home nav link on the sidebar takes the user to the index page that displays the menu for the day.
.
3. The generate report page displays a search box where a user enters a date in the format year – month – date, and on clicking on the generate report button, the user gets a downloaded pdf report of the report for that day.

#### Create Menu/Timetable

![Create menu](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/fazmyqmy5hdq2w5wce41.png)

Above is the create menu modal that pops when the create menu is clicked. It allows the user to create a new menu group, which is a combination of food items stored together under a group name to be used later in creating the menu for the day. This is to make creating the menu for the day easy and efficient.

#### Add new food

![Add new food](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/traynak7n8bfpfw02yqd.png)

To add a new food click the add new food item nav link which opens a modal with a form that collects information about the new food you want to create, after the form is filled the food is created and stored in the database.

#### Sales Page

The sales page is used by the staff selling food at the counter, anytime food is sold the staff at the counter click on the amount of food sold, and this immediately updates the database real-time.

![Sales page](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/j7ti0s10cq9dwitqiasx.png)

The sales page is accessed via the admin dashboard. Click on the **INCOME** nav link and select the location where the food is being sold, you will then be greeted with a page showing the food available in that area. The page is designed in such a way that it would take minimal effort and time to deduct food quantities, the staff selling the food just has to tap on the number of the item sold and this is immediately deducted from the database.


![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/ovq55a4b6a1c8upsknzk.png)



I and my team members presented the project on the exhibition day and it worked amazingly well here is a video of us during the fabrication process.

{% embed https://youtu.be/BfClN_kzvBE %}

To access the code for the mass-scale check my [GitHub repository](https://github.com/Pius171/PIATRON-Automated-Food-Counter-Mass-Scale.git)

In summary, our journey to create a food monitoring system for the school cafeteria was a rewarding experience that showcased the power of technology to solve real-world problems. By combining hardware innovation with software development, we've laid the foundation for a more efficient and user-friendly cafeteria experience. Our project reflects our commitment to using technology to improve everyday processes, and we look forward to future opportunities to make a positive impact through innovation.







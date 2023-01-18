
![TPLMaps](https://api.tplmaps.com/apiportal/assets/images/logo-af7d4a2a6d.svg)

[![Build Status](https://travis-ci.com/anumshk27/TPLMapDemo.svg?token=pAxNL3frqpRC6rqwAYgv&branch=master)](https://travis-ci.com/anumshk27/TPLMapDemo)
[![Version](https://img.shields.io/cocoapods/v/TPLMaps.svg?style=flat)](http://cocoapods.org/pods/TPLMaps)
[![Platform](https://img.shields.io/cocoapods/p/TPLMaps.svg?style=flat)](http://cocoapods.org/pods/TPLMaps)

## Getting Started
Before you can begin working with TPL Maps on iOS, you need to download the TPL Maps SDK for iOS.

### Step 1: Get the latest version of Xcode
To build a project using the TPL Maps SDK for iOS, you need **version 9.0** or later of [Xcode](https://developer.apple.com/xcode/).

### Step 2: Generate Config File

To use the TPLMaps SDK for iOS, you must get Config.plist file which you can then add to your iOS application.  The Config.plist is used to track API requests associated with your project for usage and billing.

**Get the latest config file**
[HERE](http://api.tplmaps.com/apiportal/#/portal/home).

This file contains configuration details, such as keys and identifiers, for the services that you have just enabled. Add the Config.plist file to your xcode project downloaded from the TPLMaps portal to start working with TPLmaps sdk.


### Step 3: Install the SDK

The TPLMap SDK for iOS is available as a CocoaPods pod. CocoaPods is an open source dependency manager for Swift and Objective-C Cocoa projects.

If you don't already have the CocoaPods tool, install it on macOS by running the following command from the terminal. For details, see the [CocoaPods Getting Started guide](https://guides.cocoapods.org/using/getting-started.html).

> sudo gem install cocoapods

Create a `Podfile` for the TPLMaps SDK for iOS and use it to install the API and its dependencies:

1. If you don't have an Xcode project yet, create one now and save it to your local machine. (If you're new to iOS development, create a Single View Application.)

2. Create a file named `Podfile` in your project directory. This file defines your project's dependencies. 

3. Edit the `Podfile` and add your dependencies. Here is an example which includes the dependencies you need for the TPLMaps SDK for iOS:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '9.3'

target 'YOUR_APPLICATION_TARGET_NAME_HERE' do
pod 'TPLMaps'
end
```

4. Save the `Podfile`

5. Open a terminal and go to the directory containing the `Podfile`:
```ruby
cd <path-to-project>
```

6. Run the `pod install` command. This will install the APIs specified in the `Podfile`, along with any dependencies they may have.

7. Close Xcode, and then open (double-click) your project's `.xcworkspace` file to launch Xcode. From this time onwards, you must use the `.xcworkspace` file to open the project.

### Step 4: Add a map
The code below demonstrates how to add a simple map to an existing ViewController. If you're creating a new app, first follow the installation instructions above, and create a new **Single View Application**.

Now, add or update a few methods inside your app's default ViewController to create and initialize an instance of `TPLMapView`.

```objective-c

- (void)viewDidLoad {

[super viewDidLoad];

//Initializes and returns a new map view for specified frame
TPLMapView * mapView = [[TPLMapView alloc] initWithFrame:self.view.bounds];

//The map view delegate
mapView.delegate = self;

//Show user location on map. Read documentation for more info
mapView.showsUserLocation = true;

//Show user location button on map. Read documentation for more info
mapView.myLocationButtonEnabled = true;

//Show map zoom controls
mapView.zoomControlsEnabled = true;

//Show compass on map
mapView.showsCompass = true;

//Show POI's in map
mapView.showsPointsOfInterest = true;

//Show Buildings on map
mapView.showsBuildings = true;

//Enum provide MapView theme Day | Night.
mapView.mapTheme = NIGHT;

//Wether pan gesture is enabled or disabled on map.
mapView.scrollEnabled = true;
    
//Wether tilt gesture is enabled or disabled on map.
mapView.tiltEnabled = true;
    
//Wether rotate gesture is enabled or disabled on map.
mapView.rotateEnabled = true;
    
//Whether all gestures should be enabled (default) or disabled.
mapView.allGesturesEnabled = true;

//Map Max zoom
mapView.maximumZoom = 20;

//Map Min zoom
mapView.minimumZoom = 10;

//Render Maps to view
[self.view addSubview:mapView];

}
```

#### Add Point On MapView
```objective-c

CLLocation * newLoc = ;

//Initilize Marker with set of coordinate
Marker * annotationPin = [Marker markerWithPosition:newLoc.coordinate];

//The string containing the Marker's Title.
annotationPin.title = @"Point";

//A Boolean value indicating whether the annotation view display in a callout bubble.
annotationPin.canShowCallout = true;

//Marker icon to render. If left nil, uses a default SDK place marker.
annotationPin.icon = [UIImage imageNamed:@"car"];

//Sets the rotation angle for the Marker in degrees
annotationPin.rotation = 60.0;

//Controls whether this marker should be flat against the Earth's surface
annotationPin.flat = false;

//Method to render marker on map
[self.mapView addMarker:annotationPin];

```

#### Add Circle On MapView
```objective-c

CLLocation * loc = ;

//Initilize Circle with set of Coordinate and radius
Circle * circle = [Circle circleWithCenterCoordinate:loc.coordinate radius:100];

//The outline width of the line in screen points.Default is 2
circle.outlineWidth = 0.1;

//A Boolean value that indicates whether the polyline is transparent.
circle.transparent = true;

//The UIColor used to render the polyline. if empty or nil default color will be Blue
circle.outlineColor = [UIColor colorWithRed:244.0/255.0 green:66.0/255.0 blue:226.0/255.0 alpha:1.0];

//Method to render Circle on map
[self.mapView drawCircle:circle];

```

#### Add Polyline On MapView
```objective-c

CLLocation * lineCoordinates1 = ;
CLLocation * lineCoordinates2 = ;

//CoordinateGeometry is colloction of CLLocationCooordinate2D
MutableCoordinateGeometry * geometry = [[MutableCoordinateGeometry alloc] init];

//Adds coordinate to the end of geometry
[geometry addCoordinate:lineCoordinates1.coordinate];
[geometry addCoordinate:lineCoordinates2.coordinate];

//Initilize Polyline with set of MutableCoordinateGeometry
PolyLine * polyline = [PolyLine polylineWithCoordinates:geometry];

//The outline width of the line in screen points.Default is 2
polyline.outlineWidth = 3;

//A Boolean value that indicates whether the polyline is transparent.
polyline.transparent = false;

//The Width of the line in screen points.Default is 2
polyline.lineWidth = 3;

//The UIColor used to render the polyline. if empty or nil default color will be Blue
polyline.outlineColor = [UIColor redColor];

//The UIColor used to fill the shape’s path
polyline.fillColor = [UIColor blueColor];

//Method to render polyline on map
[self.mapView drawPolyLine:polyline];


```
#### Add Polygon On MapView
```objective-c

//CoordinateGeometry is colloction of CLLocationCooordinate2D
MutableCoordinateGeometry * geometry = [[MutableCoordinateGeometry alloc] init];

//Adds coordinate to the end of geometry
[geometry addCoordinate:loc1.coordinate];
[geometry addCoordinate:loc2.coordinate];
[geometry addCoordinate:loc3.coordinate];
[geometry addCoordinate:loc4.coordinate];

//Initilize Polygon with set of MutableCoordinateGeometry
Polygon * polygon = [Polygon polygonWithCoordinates:geometry];

//The outline width of the line in screen points.Default is 2
polygon.outlineWidth = 0.1;

//A Boolean value that indicates whether the polyline is transparent.
polygon.transparent = true;

//The UIColor used to render the polyline. if empty or nil default color will be Blue
polygon.outlineColor = [UIColor colorWithRed:244.0/255.0 green:66.0/255.0 blue:226.0/255.0 alpha:1.0];

//Method to render Polygon on map
[self.mapView drawPolygon:polygon];

```
#### Reverse Geocoding 
```objective-c

//Create location object
CLLocation * location = [[CLLocation alloc] initWithLatitude:coordinate.latitude 
															longitude:coordinate.longitude];

//Submits a reverse-geocoding request for the specified location and return place
[Geocoder reverseGeocodeLocation:location completionHandler:^(NSArray<Place *> * placemarks, NSError * error) {
      if (error) {
         	 NSLog(@"%@", error.localizedDescription);
      }else {
			NSLog(@"placemark %@", placemarks.description);
      }
 } ];

```
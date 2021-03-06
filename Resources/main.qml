import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtDataVisualization 1.15

import Pop 1.0

Window {
    property int screenHeight: Screen.height -1
    property int screenWidth: Screen.width
    visible: true
    width: 640
    height: 480
    title: qsTr("DataVisualisation")

    Item {
        anchors.fill: parent

        Bars3D {
            anchors.fill: parent
//            barSpacing: 10
            barSpacingRelative: true
            barThickness: 0.5

            Bar3DSeries {
                itemLabelFormat: "@colLabel, @rowLabel: @valueLabel"
                meshAngle: 5
                ItemModelBarDataProxy {
                    itemModel: PopModel {
                        list: popList
                    }

                    rowRole: "year"
                    columnRole: "city"
                    valueRole: "population"
                }
            }
        }
    }

}

//Item {
//    width: 640
//    height: 480

//    Bars3D {
//        width: parent.width
//        height: parent.height

//        Bar3DSeries {
//            itemLabelFormat: "@colLabel, @rowLabel: @valueLabel"

//            ItemModelBarDataProxy {
//                itemModel: dataModel
//                // Mapping model roles to bar series rows, columns, and values.
//                rowRole: "year"
//                columnRole: "city"
//                valueRole: "expenses"
//            }
//        }
//    }

//    ListModel {
//        id: dataModel
//        ListElement{ year: "2012"; city: "Oulu";     expenses: "4200"; }
//        ListElement{ year: "2012"; city: "Rauma";    expenses: "2100"; }
//        ListElement{ year: "2012"; city: "Helsinki"; expenses: "7040"; }
//        ListElement{ year: "2012"; city: "Tampere";  expenses: "4330"; }
//        ListElement{ year: "2013"; city: "Oulu";     expenses: "3960"; }
//        ListElement{ year: "2013"; city: "Rauma";    expenses: "1990"; }
//        ListElement{ year: "2013"; city: "Helsinki"; expenses: "7230"; }
//        ListElement{ year: "2013"; city: "Tampere";  expenses: "4650"; }
//    }
//}

import { dark } from "@eva-design/eva";
import { StyleSheet } from "react-native";

export const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  header: {
    paddingHorizontal: 20,
    paddingVertical: 20,
  },
  layout: {
    position: "relative",
    flex: 1,
    paddingHorizontal: 20,
    paddingVertical: 24,
  },
  divider: {
    height: 2,
  },
  bottomNavigationContainer: {
    position: "absolute",
    bottom: 0,
    left: 0,
    right: 0,
    zIndex: 1,
  },
  bottomNavigationFloatingContainer: {
    flexDirection: "row",
    justifyContent: "center",
    bottom: 16,
  },
  bottomNavigation: {
    borderRadius: 8,
    backgroundColor: dark["color-primary-transparent-200"],
  },
  bottomNavigationFloating: {
    width: 200,
  },
  bottomNavigationIndicator: {
    borderRadius: 8,
  },
  bottomNavigationFloatingIndicator: {
    width: "90%",
  },
});

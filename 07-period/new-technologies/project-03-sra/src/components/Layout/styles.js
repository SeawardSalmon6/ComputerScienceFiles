import { StyleSheet } from "react-native";

export default StyleSheet.create({
  root: {
    position: "relative",
    flex: 1,
  },
  contentContainer: {
    flexGrow: 1,
    paddingVertical: 16,
    paddingHorizontal: 40,
  },
  headerContainer: {
    paddingVertical: 16,
    marginBottom: 32,
  },
  headerContentContainer: {
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "space-between",
  },
  accessoryLeft: {
    flexDirection: "row",
    alignItems: "center",
    gap: 8,
  },
  accessoryRight: {
    flexDirection: "row",
    alignItems: "center",
    gap: 8,
  },
  navigationButton: {
    alignItems: "center",
    justifyContent: "center",
    padding: 8,
  },
  navigationIcon: {
    height: 32,
  },
  logo: {
    width: 100,
  },
});

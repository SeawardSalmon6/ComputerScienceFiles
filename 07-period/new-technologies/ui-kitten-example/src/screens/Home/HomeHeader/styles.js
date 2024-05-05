import { StyleSheet } from "react-native";

export const styles = StyleSheet.create({
  buttonsContainer: {
    flexDirection: "row",
    justifyContent: "space-between",
  },
  button: {
    alignItems: "center",
    justifyContent: "center",
    paddingVertical: 8,
    paddingHorizontal: 8,
    marginVertical: 0,
    marginHorizontal: 4,
    borderRadius: 8,
  },
  icon: {
    width: 26,
    height: 26,
    fill: "#ffffff",
  },
  avatar: {
    width: 48,
    height: 48,
  },
  header: {
    paddingHorizontal: 20,
    paddingVertical: 20,
  },
  titleContainer: {
    flexDirection: "row",
    alignItems: "flex-start",
    marginTop: 24,
  },
  title: {
    fontSize: 16,
    fontWeight: "bold",
  },
});

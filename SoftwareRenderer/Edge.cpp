#include "Edge.h"

Edge::Edge(Gradients gradients, Vertex start, Vertex end, int startIndex) {
	m_yStart = (int)ceil(start.getPos().y);
	m_yEnd = (int)ceil(end.getPos().y);
	m_xStep = (end.getPos().x - start.getPos().x) / (end.getPos().y - start.getPos().y);
	float yPre = (float)m_yStart - start.getPos().y;
	m_xPos = start.getPos().x + yPre * m_xStep;
	float xPre = m_xPos - start.getPos().x;

	m_texCoords = gradients.getTexCoords(startIndex) + gradients.getTexCoordsYStep() * yPre + gradients.getTexCoordsXStep() * xPre;
	m_texCoordsStep = gradients.getTexCoordsYStep() + gradients.getTexCoordsXStep() * m_xStep;
}

void Edge::step() {
	m_xPos += m_xStep;
	m_texCoords += m_texCoordsStep;
}

int Edge::getYStart() {
	return m_yStart;
}

int Edge::getYEnd() {
	return m_yEnd;
}

float Edge::getXPos() {
	return m_xPos;
}

const Vec2& Edge::getTexCoords() {
	return m_texCoords;
}
